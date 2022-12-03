#include <iostream>

template <int n>
struct math_factorial
{
	static constexpr int a = n * math_factorial<n - 1>::a;
};

template <>
struct math_factorial<0> 
{
    static constexpr int a = 1;
};

template <int k, int n>
struct math_Binomal_Coefficient
{
	static constexpr int ans = math_factorial<n>::a / (math_factorial<k>::a * math_factorial<n - k>::a);
};

int main()
{
	std::cout << math_Binomal_Coefficient<5, 12>::ans;
}