#include <iostream>


class ErgJ
{
public:
    double joules;
    static const int jTe = 10000000;
    static const long int jTv = 6000000000000000000;
    double getV() const { return joules * jTv;}
    double getE() const { return joules * jTe; }
    double getJ() const { return joules;}
    void setJ(double a){ joules = a;}
    void setE(double a){ joules = a/ jTe;}
    void setV(double a){ joules = a/ jTv;}
};

int main()
{
    ErgJ erg;
    double a;
    std::cout << " Input energy in Joules:" << '\t' << std::endl;
    std::cin >> a;
    erg.setJ(a);
    std::cout << "This energy in ergs:" << erg.getE() << std::endl;
    std::cout << " Input energy in ergs:" << '\t' << std::endl;
    std::cin >> a;
    erg.setE(a);
    std::cout << "This energy in evs:" << erg.getV() << std::endl;
}