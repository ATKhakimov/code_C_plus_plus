#include <iostream>
#include <exception>
#include <vector>
#include <bitset>


void memErorr() try
{
	int* arr = new int[99999999999];
}
catch (const std::exception& ex)
{
	std::cerr << "memErorrt: " << ex.what() << std::endl;
	return;
}
class Shape {
public:
   virtual void virtualfunc() const {}
};

class Circle: public Shape {
public:
   virtual void virtualfunc() const {}
};
void dosmth() try
{
    Shape shape_instance;
    Shape& ref_shape = shape_instance;
    Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
}
catch (const std::exception& ex)
{
	std::cerr << "error: " << ex.what()<< std::endl;
	return;
}
void makevector() try{
    std::vector<int> v(100 + static_cast<size_t>(-1) / sizeof(int));
}
catch (const std::exception& ex)
{
	std::cerr << "error lenght: " << ex.what()<< std::endl;
	return;
}
void bit(const std::string& str) try
{
	std::bitset<10>{str};
}
catch (const std::exception& ex)
{
	std::cerr << "error bit: " << ex.what()<< std::endl;
	return;
}
int main() try
{
	memErorr();
    dosmth();
    try
    {
        std::vector<int> v(100 + static_cast<size_t>(-1) / sizeof(int));
    }
    catch (const std::exception& ex)
    {
        std::cout << "erorr: " << ex.what() << std::endl;
    }
   bit({"A"});
   int a = -0.0;
   try {
    std::vector<int> vv;
    vv.resize(vv.max_size()+1);
  }
  catch (const std::exception& ex) {
	  std::cerr << "Length error: " << ex.what() << std::endl;
  }
}
catch(...){
}
