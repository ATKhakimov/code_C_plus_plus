#include <iostream>
#include <vector>

template <int n>
constexpr int math_n_prime()
{
	std::vector <int> vec(n);
	int i = 0;
	int ints = 2;
	while (i < n)
	{
		int j = 0;
		while (j < i/2)
		{
			if (ints % vec[j] == 0)
			{
				++ints;
				j = 0;
			}
			++j;
		}
		vec[i] = ints;
		++ints;
		++i;
		
	}
	return vec.back();
}

int main()
{	
	std::cout << math_n_prime<33>();
}