#include <iostream>

#include <iomanip>

#include <cmath>

using std::cout;
//using std::setw;
//using std::hex;
//using std::uppercase;
//using std::setfill;
using std::endl;
using std::string;
using std::cin;
//using std::boolalpha;
//using std::showpos;

int main() {
  double long a, b, c, d, x1, x2;
  cout << "Введите последовательно коэффициенты a,b,c уравнения ax^2 + bx + c = 0\n";
  cin >> a >> b >> c;
  d = b * b - 4 * a * c;
  if (d == 0) {
    x1 = b / (2 * a);
    cout << '\n' << "*************** OUTPUT ***************" << "\n\n";
    cout << "x =  " << -x1 << "\n";
  }
  if (d < 0)
    cout << '\n' << "*************** OUTPUT ***************" << "\n\n";
    cout << "no solutions";
  if (d > 0) {
    x1 = ((-b) + sqrt(d)) / (2 * a);
    x2 = ((-b) - sqrt(d)) / (2 * a);
    cout << '\n' << "*************** OUTPUT ***************" << "\n\n";
    cout << "x1 = " << x1 << "\n";
    cout << "x2 = " << x2 << "\n";
  }
  
  return 0;
  
}
