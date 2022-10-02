#include <iostream>


enum Month
{
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
	switch(a){
	case Month::January:
		answer = 31;
		break;
	case Month::February:
		if( b % 4 == 0){ answer = 29;}
		else{ answer = 28;}
		break;
	case Month::March:
		answer = 31;
		break;
	case Month::April:
		answer = 30;
		break;
	case Month::May:
		answer = 31;
		break;
	case Month::June:
		answer = 30;
		break;
	case Month::July:
		answer = 31;
		break;
	case Month::August:
		answer = 31;
		break;
	case Month::September:
		answer = 30;
		break;
	case Month::October:
		answer = 31;
		break;
	case Month::November:
		answer = 30;
		break;
	case Month::December:
		answer = 30;
		break;
	default:
		answer = -1;
	}
	std::cout << answer;
}