#include <iostream>


class Somebody
{
public: 
        Somebody(int a = 0, std::string b = "Smith"){}
private:
    void name() const
    {
        std::cout << "John";
    }
    void Fname() const
    {
        std::cout << "******";
    }
    friend class Clerk;
};

class Clerk
{
private:
    bool law = 1;
    static void ClerksLaw( Somebody & sbd){
        return sbd.name();
    }
    friend void AcquaintanceAsk ( Somebody &);
    
    //if (law == 1){
      //  friend void AcquaintanceAsk ( Somebody &); я не понимаю что не так с if ( expected unq-id before)
    //}else {
      //  friend void Denided ();
    //}
};

void AcquaintanceAsk(Somebody & sbd){ 
    return Clerk::ClerksLaw(sbd);
}



int main()
{
	Somebody person;
    AcquaintanceAsk(person);
}

