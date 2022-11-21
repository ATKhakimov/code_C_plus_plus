#include <iostream>
template <typename T, typename... Types>
auto fold(T a, Types... b)
{
	return (sizeof(a) + ... + sizeof(b));
}
auto deff()
{
	return 0;
}
template <typename T, typename... Types>
auto deff(T a, Types... b)
{
	return sizeof(a) + deff(b...);
}

int main()
{
    int ans = 0;
    ans = sizeof(15) + sizeof(14);
	std::cout << fold(15, 14) << std::endl;
	std::cout << deff(15, 14) << std::endl;
	std::cout << ans << std::endl;
}