#include <iostream>
#include <cmath>

constexpr int math_updated_factorial(int n)
{
    if(n) return n * math_updated_factorial(n - 1);
	else return 1;
}
constexpr double func(int n)
{
    if(n) return 1/static_cast<double>(math_updated_factorial(n)) + func(n - 1);
	else return 1;
}

constexpr double func2(int n)
{
    if(n) return pow(static_cast<double>(math_updated_factorial(n)) + func(n - 1), -1);
	else return 1;
}

int main()
{
	std::cout << func(20) << " is not " << func2(20);
}