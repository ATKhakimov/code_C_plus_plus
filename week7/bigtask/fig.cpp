#include "fig.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

double dist(std::pair<double, double> p1, std::pair<double, double> p2) {
  return std::sqrt((p2.first - p1.first) * (p2.first - p1.first) +
                   (p2.second - p1.second) * (p2.second - p1.second));
};

std::ostream &operator<<(std::ostream &stream, Figured const *Figured) {
  stream << Figured->param();
  return stream;
}

Polygon::Polygon(const std::vector<std::pair<double, double>> points_)
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
Triangle::Triangle(const std::vector<std::pair<double, double>> points)
    : Polygon(points) {
  std::pair<double, double> a{points[1].first - points[0].first,
                              points[1].second - points[0].second};
  std::pair<double, double> b{points[1].first - points[2].first,
                              points[1].second - points[2].second};
}

Quadrangle::Quadrangle(const std::vector<std::pair<double, double>> points)
    : Polygon(points) {}

Parallelogram::Parallelogram(
    const std::vector<std::pair<double, double>> points)
    : Quadrangle(points) {}

Rhombus::Rhombus(const std::vector<std::pair<double, double>> points)
    : Parallelogram(points) {}

Rectangle::Rectangle(const std::vector<std::pair<double, double>> points)
    : Parallelogram(points) {
  std::pair<double, double> v(points[1].first - points[2].first,
                              points[1].second - points[2].second);
  std::pair<double, double> u(points[1].first - points[0].first,
                              points[1].second - points[0].second);
}

Square::Square(const std::vector<std::pair<double, double>> points)
    : Parallelogram(points), Rectangle(points), Rhombus(points) {}
