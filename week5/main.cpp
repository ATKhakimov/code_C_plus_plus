#include <iostream>
#include <vector>
#include "text.h"

int main()
{	
   Lesson math, physics;
   Student Valeria, Poul;
   math.name = "math";
   math.amount = 3;
   math.complexcity = 8;
   physics.name = "physics";
   physics.amount = 2;
   physics.complexcity = 6;
   Valeria.surname = "Yunkina";
   Valeria.age = 19;
   Valeria.sex = 0;
   Poul.surname = "Smith";
   Poul.age = 21;
   Poul.sex = 1;
   std::cout << "U can to make your student" << std::endl;
   std::string a;
   int b;
   bool c;
   Lesson uuser;
   std::cout << "Input surname:" << '\t'; std::cin >> a; 
   std::cout << "Input age:" << '\t'; std::cin >> b;
   std::cout << "Input sex (0/1):" << '\t'; std::cin >> c;
   Student user {a, b, c};
   std::cout << "U can make your Lesson" << std::endl;
   std::cout << "Input name:" << '\t'; std::cin >> a; uuser.name = a;
   std::cout << "Input amount:" << '\t'; std::cin >> b; uuser.amount = b;
   std::cout << "Input complexcity:" << '\t'; std::cin >> b; uuser.complexcity = b;
   std::cout << "Want to add all students to your lesson or your student for all lessons? (1/2):" << '\t'; std::cin >> b;
   if ( b == 1)
   {
       add(Valeria, uuser);
       add(Poul, uuser);
       add(user, uuser);
   } else{
       add(user, uuser);
       add(user, math);
       add(user, physics);
   }
   
   add(Valeria, physics);
   add(Poul, physics);
   add(Poul, math);
   int inn;
   std::vector<Lesson> l {math, physics, uuser};
   std::vector<Student> s {Valeria, Poul, user};
   std::cout << "Write random number from 0 to" <<" " << s.size() - 1 << std::endl;
   std:: cin >> inn;
   
   std::cout << "U choose" <<" " << s[inn].surname << std::endl;
   std::cout << "Lessons of your student is:" << std::endl;
   outt(s[inn]);
}