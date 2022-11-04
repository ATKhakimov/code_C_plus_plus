#include <iostream>
#include <exception>

void memErorr() try
{
	int* arr = new int[99999999999];
}
catch (std::exception& ex)
{
	std::cerr << "memErorrt: " << ex.what();
	return;
}
int main() try
{
	memErorr();
}
catch(...){}