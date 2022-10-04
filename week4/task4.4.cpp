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
	case 2:
		if( b % 4 == 0){ answer = 29;}
		else{ answer = 28;}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		answer = 31;
		break;
	default:
		answer = 30;
	}
	std::cout << answer;
}