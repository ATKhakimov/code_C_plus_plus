
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>

using coordinates = std::pair<double, double>;

//inline double constexpr pi = 3.14;
auto pi = M_PI;

double dist(coordinates p1, coordinates p2);

class Figured {
public:
  virtual double per() const = 0;

  virtual double sq() const = 0;

  virtual std::string param() const = 0;

  friend std::ostream &operator<<(std::ostream &stream, Figured const *figure);
};

class Polygon : public Figured {
public:
  explicit Polygon(const std::vector<coordinates> points_);

  double per() const override;

  double sq() const override;

  virtual std::string param() const override { return "Polygon."; }

protected:
  std::vector<coordinates> points;
  std::vector<double> lines;

private:
  virtual void l_size() {
    size_t size = std::size(points);
    for (size_t i = 0; i < size; i++) {
      lines.push_back(dist(points[i], points[(i + 1) % size]));
    }
  };
};

class Triangle : public Polygon {
public:
  explicit Triangle(const std::vector<coordinates> points);

  double sq() const override {
    double r = per() / 2.0;
    for (int i = 0; i < 3; i++) {
      r *= (r - lines[i]);
    }
    return std::sqrt(r);
  };

  virtual std::string param() const override { return "Triangle."; }
};

class Quadrangle : public Polygon {
public:
  explicit Quadrangle(const std::vector<coordinates> points);

  virtual std::string param() const override { return "Quadrangle."; }
};

class Parallelogram : public Quadrangle {
public:
  explicit Parallelogram(const std::vector<coordinates> points);

  virtual std::string param() const override { return "Parallelogram."; }
};

class Rhombus : public virtual Parallelogram {
public:
  explicit Rhombus(const std::vector<coordinates> points);

  double per() const override { return 4 * lines[0]; }

  double sq() const override {
    double d1 = dist(points[0], points[2]);
    double d2 = dist(points[1], points[3]);

    return 0.5 * d1 * d2;
  }

  virtual std::string param() const override { return "Rhombus."; }
};

class Rectangle : public virtual Parallelogram {
public:
  explicit Rectangle(const std::vector<coordinates> points);

  double sq() const override { return lines[0] * lines[1]; }

  virtual std::string param() const override { return "Rectangle."; }
};

class Square : public Rectangle, public Rhombus {
public:
  explicit Square(const std::vector<coordinates> points);

  double per() const override final { return 4* lines[0]; };

  double sq() const override final { return Rectangle::sq(); };

  virtual std::string param() const override { return "Square."; }
};

class Ellipse : public Figured {
public:
  explicit Ellipse(coordinates center_, double a_, double b_)
      : center(center_), a(a_), b(b_) {}

  virtual double per() const override final {
    return 4 * (pi * a * b + (a - b) * (a - b)) / (a + b);
  }

  virtual double sq() const override final { return pi * a * b; };

  virtual std::string param() const override { return "Ellipse."; }

protected:
  coordinates center;
  double a;

private:
  double b;
};

class Circle : public Ellipse {
public:
  explicit Circle(coordinates center, double r)
      : Ellipse(center, r, r){};

  virtual std::string param() const override { return "Circle."; }
};

double dist(coordinates p1, coordinates p2) {
  return std::sqrt((p2.first - p1.first) * (p2.first - p1.first) +
                   (p2.second - p1.second) * (p2.second - p1.second));
};

std::ostream &operator<<(std::ostream &stream, Figured const *Figured) {
  stream << Figured->param();
  return stream;
}

Polygon::Polygon(const std::vector<coordinates> points_)
    : points(points_) {
  l_size();
};

double Polygon::per() const {
  double perimeter = 0;
  for (double side : lines)
    perimeter += side;

  return perimeter;
}

double Polygon::sq() const {
  double squarer = 0;
  for (size_t i = 1; i < std::size(points) - 1; i++) {
    Triangle parts({points[0], points[i], points[i + 1]});
    squarer += parts.sq();
  }

  return squarer;
}
Triangle::Triangle(const std::vector<coordinates> points)
    : Polygon(points) {
  coordinates a{points[1].first - points[0].first,
                              points[1].second - points[0].second};
  coordinates b{points[1].first - points[2].first,
                              points[1].second - points[2].second};
}

Quadrangle::Quadrangle(const std::vector<coordinates> points)
    : Polygon(points) {}

Parallelogram::Parallelogram(
    const std::vector<coordinates> points)
    : Quadrangle(points) {}

Rhombus::Rhombus(const std::vector<coordinates> points)
    : Parallelogram(points) {}

Rectangle::Rectangle(const std::vector<coordinates> points)
    : Parallelogram(points) {
  coordinates v(points[1].first - points[2].first,
                              points[1].second - points[2].second);
  coordinates u(points[1].first - points[0].first,
                              points[1].second - points[0].second);
}

Square::Square(const std::vector<coordinates> points)
    : Parallelogram(points), Rectangle(points), Rhombus(points) {}

int main() {
  std::vector<Figured *> figures{new Circle({1, 12}, 10),
                           new Triangle({{0, 0}, {1, 1}, {0, 10}})};

  for (auto f : figures) {
    std::cout << f << '\n' <<" S and P :"<< f->sq() << "&" << f->per() << std::endl;
  }
  for (auto f: figures) delete f;
}