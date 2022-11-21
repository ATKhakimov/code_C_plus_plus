#include <iostream>
template <typename Type, typename... Types>
auto make(Types... q)
{
	Type* link = new Type(q...);
	return link;
}
class User
{
public:
	User(int a): a1 { a }{	}
	int a1;
};
int main()
{
	User* link = make<User>(14);
}