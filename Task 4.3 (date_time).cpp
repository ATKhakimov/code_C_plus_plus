#include <iostream>


using std::cout;
using std::endl;
//using std::string;
using std::cin;


struct Date_time 
{
	unsigned short day : 5;   
	unsigned short month : 4; 
	unsigned short year : 7;  
	unsigned short hour : 5;  
	unsigned short minute : 6;
	unsigned short second : 6;
	unsigned short millisecond : 10;
};

int main()
{	
	Date_time date; 
	int a;      
	cout << "Input Day (1-31):" << '\t'; cin >> a; date.day = a; /* we cannt use "cin >> d.day", because there are no pointers to bit-fields*/
	cout << "Input Month (1-12):" << '\t'; cin >> a; date.month = a;
	cout << "Input Year (00-99) :" << '\t'; cin >> a; date.year = a;
	cout << endl << "Input Hour (0-24):" << '\t'; cin >> a; date.hour = a;
	cout << "Input Minute (0-60):" << '\t'; cin >> a; date.minute = a;
	cout << "Input Seconds (0-60):" << '\t'; cin >> a; date.second = a;
	cout << "Input Milliseconds (0-1000):" << '\t'; cin >> a; date.millisecond = a;

	cout << endl << "********** Date info **********" << endl << date.day << "." << date.month << ".20" << date.year << " " << endl;
	cout << date.hour << ":" << date.minute << ":" << date.second << ":" << date.millisecond << endl;
}