#include <iostream>


#pragma pack(push, 1)
struct Date_time 
{
	unsigned millisecond : 10;
	unsigned year : 7; 
	unsigned day : 5;   
	unsigned month : 4; 
	unsigned hour : 5;  
	unsigned minute : 6;
	unsigned second : 6;
	
};
#pragma pack(pop)

int main()
{	
	Date_time date; 
	int a;
	std::cout << sizeof(Date_time) << std::endl;      
	std::cout << "Input Day (1-31):" << '\t'; std::cin >> a; date.day = a; 
	std::cout << "Input Month (1-12):" << '\t'; std::cin >> a; date.month = a;
	std::cout << "Input Year (00-99) :" << '\t'; std::cin >> a; date.year = a;
	std::cout << std::endl << "Input Hour (0-24):" << '\t'; std::cin >> a; date.hour = a;
	std::cout << "Input Minute (0-60):" << '\t'; std::cin >> a; date.minute = a;
	std::cout << "Input Seconds (0-60):" << '\t'; std::cin >> a; date.second = a;
	std::cout << "Input Milliseconds (0-1000):" << '\t'; std::cin >> a; date.millisecond = a;

	std::cout << std::endl << "********** Date info **********" << std::endl << date.day << "." << date.month << ".20" << date.year << " " << std::endl;
	std::cout << date.hour << ":" << date.minute << ":" << date.second << ":" << date.millisecond << std::endl;
}