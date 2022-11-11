#include "fig.hpp"
#include <vector>

int main() {
  std::vector<Figured *> f{new Circle({1, 12}, 10),
                           new Triangle({{0, 0}, {1, 1}, {0, 10}})};

  for (auto f : f) {
    std::cout << f << '\n' <<" S and P :"<< (*f).sq() << "&" << (*f).per() << std::endl;
  }
}
