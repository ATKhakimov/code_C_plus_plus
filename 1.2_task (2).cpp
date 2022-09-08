#include <iostream>

#include <cmath>

using std::cout;
//using std::setw;
//using std::hex;
//using std::uppercase;
//using std::setfill;
using std::endl;
//using std::string;
using std::cin;
//using std::boolalpha;
//using std::showpos;

int main() {
  setlocale(LC_ALL, "Russian");
  const double h = pow(10, 5);
  const double m = pow(10, 3);
  const double a = pow(10, 7);
  const double k = 3 * pow(10, -10);
  int b;
  double long c;
  cout << "Выберете перевод из СИ в СГС, который вам нужно, написав номер." << endl;
  cout << "1) Сила: H -> дин " << endl;
  cout << "2) Масса: кг -> г " << endl;
  cout << "3) Работа: дж -> эрг " << endl;
  cout << "4) Заряд: кл -> СГС - единица заряда " << endl;
  cin >> b;
  cout << "Введите величину единицы: " << endl;
  cin >> c;
  switch (b) {
  case 1:
    cout << c << " Ньютонов = " << c * h << " дин";
    break;
  case 2:
    cout << c << " Килограмм = " << c * m << " грамм";
    break;
  case 3:
    cout << c << " Джоулей = " << c * a << " эрг";
    break;
  case 4:
    cout << c << " Кулон = " << c * k << " СГС - единиц заряда";
    break;
  }

  return 0;

}
