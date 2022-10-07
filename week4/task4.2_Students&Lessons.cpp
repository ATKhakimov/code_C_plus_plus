#include <iostream>
#include <vector>

struct Student;
struct Lesson;

struct Lesson
{
    std::vector<Student*> clas;
    std::string name;   
    int amount;
    int complexcity;
    Lesson() : name("Test1"), amount(0), complexcity(0){};
};

struct Student
{
    std::vector<Lesson*> lessons;
    std::string surname;
    int age;
    bool sex;
    Student() : surname("Test"), age(0), sex(0) {};
    
    
};

void add(Student& student, Lesson& lesson )
{
    student.lessons.push_back(&lesson);
    lesson.clas.push_back(&student);
}

void outt( Lesson& lesson)
{
    for (int i = 0; i < lesson.clas.size(); i++){
        std::cout <<(*lesson.clas[i]).surname << std::endl;
    }
}

void outt( Student& student)
{
    for (int i = 0; i < student.lessons.size(); i++){
        std::cout <<(*student.lessons[i]).name << std::endl;
    }
}


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
   
   add(Valeria, physics);
   add(Poul, physics);
   add(Poul, math);
   
   std::vector<Lesson> l {math, physics};
   std::vector<Student> s {Valeria, Poul};
   
   std::cout << "Уроки Poul" << std::endl;
   outt(s[1]);
   std::cout << "Класс физики" << std::endl;
   outt(l[1]);

   
   
   
   
   
   
   
	
	

}