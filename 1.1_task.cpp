#include <iostream>
#include <iomanip>

using std::cout; using std::setw; using std::hex; using std::uppercase; using std::setfill;
using std::endl; using std::string; using std::cin; using std::boolalpha; using std::showpos;

int main() {
    string name, a;
    int price, temperature;
    bool hasCashback;
    cout << "Product's name: ";
    cin >> name;
    cout << "Product's price: ";
    cin >> price;
    cout << "Is cash-back available for this product? (true/false) ";
    cin >> a;
    if (a == "true"){
        hasCashback = 1;
    } else{
        hasCashback = 0;
    }
    cout << "Maximum storing temperature: ";
    cin >> temperature;

    cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    cout << name << '\n';
    cout <<"Price:"<< setfill('.') << setw(18) << uppercase << hex << price << endl;
    cout <<"Has cash-back"<< setfill('.') << setw(11) << boolalpha << hasCashback << endl;
    cout <<"Max temperature:"<< setfill('.') << setw(8) << std::dec << showpos << temperature<< endl;


    return 0;
}
