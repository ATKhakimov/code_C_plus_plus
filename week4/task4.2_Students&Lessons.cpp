#include <iostream>
#include <vector>

struct Student;

struct Lesson
{
    Student * vector <Student> class_ptr;
    std::string name;   
    int amount;
    int complexcity;
};

struct Student
{
    Lesson * lessons_ptr[3];
    /*lessons_ptr = new Lesson[3];*/
    std::string surname;
    int age;
    bool sex;
    std::string *p;
    double y()
    {
        return age * 2;
    };
    Student()
    {
        surname = "test";
        age = 0;
        sex = 0;
    }
    
};

int main()
{	
   Lesson math, physics, sport;
   Student Valeria, Poul, Nikita, Sasha;
   math.name = "math";
   math.amount = 3;
   math.complexcity = 8;
   Poul.lessons_ptr[0] = &math;
   Poul.p = &math.name;
   Poul.lessons_ptr[1] = &physics;
   Valeria.lessons_ptr[0] = &physics;
   physics.class_ptr[0] = &Valeria;
   physics.class_ptr[1] = &Poul;
   math.class_ptr[0] = &Poul;
   physics.name = "physics";
   physics.amount = 2;
   physics.complexcity = 6;
   Valeria.surname = "Yunkina";
   Valeria.age = 19;
   Valeria.sex = 0;
   Poul.surname = "Smith";
   Poul.age = 21;
   Poul.sex = 1;
 
   Lesson LPoul;
   Lesson arr[3];
   std::cout << "Poul Smith lessons are:" << std::endl;
   for (int i = 0; i < 2; i++){
      arr[i] = *Poul.lessons_ptr[i]; 
   }
   for (int i = 0; i < 2; i++){
        std::cout << arr[i].name << std::endl;
   }
 
   std::cout <<"Physics class is:" << std::endl;
   Student arrr[3];
   for (int i = 0; i < 2; i++){
        arrr[i] = *physics.class_ptr[i]; 
   }
   for (int i = 0; i < 2; i++){
        std::cout << arrr[i].surname << std::endl;
   }
   
   
   
   
   
   
	
	

}