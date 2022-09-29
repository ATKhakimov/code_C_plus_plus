#include <iostream>


using std::cout;
using std::endl;
using std::string;
using std::cin;

const int January { 31 };
const int February { 28 };
const int March { 31 };
const int April { 30 };
const int May { 31 };
const int June { 30 };
const int July { 31 };
const int August { 31 };
const int September { 30 };
const int October { 31 };
const int November { 30 };
const int December { 31 };

int main()
{	
    int a;
    unsigned long int b;
    cout << "Write the number of the month" << endl;
	cout << "Enter mounth:" << '\t'; cin >> a;
	cout << "Enter year:" << '\t'; cin >> b;
	switch (a)
	{
	    case 1:
	        cout << January;
	        break;
	    case 2:
	        if ( b % 4 == 0 ){
	            cout << February + 1;
	            break;
	        } else {
	          cout << February;
	          break;
	        }
	    case 3  :
	        cout << March;
	        break;
	    case 4:
	        cout << April;
	        break;
	    case 5:
	        cout << May;
	        break;
	    case 6:
	        cout << June;
	        break;
	    case 7:
	        cout << July;
	        break;
	    case 8:
	        cout << August;
	        break;
	    case 9:
	        cout << September;
	        break;
	    case 10:
	        cout << October;
	        break;
	    case 11:
	        cout << November;
	        break;
	    case 12:
	        cout << December;
	        break;
	    default:
	        cout << "Smt incorrect";
	}
	

}