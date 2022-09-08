#include <iostream>

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

void my_swap(int a, int b){
    a += b;
    b = a - b;
    a = a - b;
    cout << '\n' << "*************** OUTPUT ***************" << "\n\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
int main() {
  int a, b;
  cout << "Последовательно введите переменные которые вы хотите поменять местами:" << endl;
  cin >> a >> b;
  my_swap(a, b);
  
  return 0;
  
}
