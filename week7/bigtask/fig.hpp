#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

inline double constexpr pi = 3.14;

double dist(std::pair<double, double> p1, std::pair<double, double> p2);

class Figured {
public:
  virtual double per() const = 0;

  virtual double sq() const = 0;

  virtual std::string param() const = 0;

  friend std::ostream &operator<<(std::ostream &stream, Figured const *figure);
};

class Polygon : public Figured {
public:
  explicit Polygon(const std::vector<std::pair<double, double>> points_);

  double per() const override;

  double sq() const override;

  virtual std::string param() const override { return "Polygon."; }

protected:
  std::vector<std::pair<double, double>> points;
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
  explicit Triangle(const std::vector<std::pair<double, double>> points);

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
  explicit Quadrangle(const std::vector<std::pair<double, double>> points);

  virtual std::string param() const override { return "Quadrangle."; }
};

class Parallelogram : public Quadrangle {
public:
  explicit Parallelogram(const std::vector<std::pair<double, double>> points);

  virtual std::string param() const override { return "Parallelogram."; }
};

class Rhombus : public virtual Parallelogram {
public:
  explicit Rhombus(const std::vector<std::pair<double, double>> points);

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
  explicit Rectangle(const std::vector<std::pair<double, double>> points);

  double sq() const override { return lines[0] * lines[1]; }

  virtual std::string param() const override { return "Rectangle."; }
};

class Square : public Rectangle, public Rhombus {
public:
  explicit Square(const std::vector<std::pair<double, double>> points);

  double per() const override final { return 4* lines[0]; };

  double sq() const override final { return Rectangle::sq(); };

  virtual std::string param() const override { return "Square."; }
};

class Ellipse : public Figured {
public:
  explicit Ellipse(std::pair<double, double> center_, double a_, double b_)
      : center(center_), a(a_), b(b_) {}

  virtual double per() const override final {
    return 4 * (pi * a * b + (a - b) * (a - b)) / (a + b);
  }

  virtual double sq() const override final { return pi * a * b; };

  virtual std::string param() const override { return "Ellipse."; }

protected:
  std::pair<double, double> center;
  double a;

private:
  double b;
};

class Circle : public Ellipse {
public:
  explicit Circle(std::pair<double, double> center, double r)
      : Ellipse(center, r, r){};

  virtual std::string param() const override { return "Circle."; }
};
