#include <iostream>
void mean(double a, double b)
{
	std::cout <<"Mean is:" << (a + b)/2 << std::endl;
}
template <typename q, typename... qq>
auto Call(q input, qq... inputs){input(inputs...);}
int main()
{
	Call(mean, 14.5, 15.6);
}