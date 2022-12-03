#include <iostream>

template <int n>
struct math_Fibbonachi
{
	static constexpr int a = math_Fibbonachi<n-1>::a + math_Fibbonachi<n-2>::a;
};

template <>
struct math_Fibbonachi<0>
{
	static constexpr int a = 0;
};

template <>
struct math_Fibbonachi<1>
{
	static constexpr int a = 1;
};

int main()
{
	std::cout << math_Fibbonachi<3>::a; 
}