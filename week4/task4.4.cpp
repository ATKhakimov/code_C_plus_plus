#include <iostream>


enum class Month{
January = 1,
February,
March,
April,
May,
June,
July,
August,
September,
October,
November,
December
};


int main()
{	
    int a, answer;
    unsigned long int b;
    std::cout << "Write the number of the month from 1 to 12:" << '\t'; std::cin>>a;
	std::cout << "Enter year in 4-number format:" << '\t'; std::cin >> b;
	switch(static_cast<int>(a)){
	case static_cast<int>(Month::February):
		if( b % 4 == 0){ answer = 29;}
		else{ answer = 28;}
		break;
	case static_cast<int>(Month::January) | static_cast<int>(Month::March) | static_cast<int>(Month::May) | static_cast<int>(Month::July) | static_cast<int>(Month::August) | static_cast<int>(Month::October) | static_cast<int>(Month::December)  :
		answer = 31;
		break;
	default:
		answer = 30;
	}
	std::cout << answer;
}