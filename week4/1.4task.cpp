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
    Lesson (std::string n, int a, int c){
        name = n;
        amount = a;
        complexcity = c;
    }
    
    void outCompexcity() const
    {
        std::cout << "complexcity" << " " << name <<" is" << complexcity;
    }
    ~Lesson() = default;
};

struct Student
{
    std::vector<Lesson*> lessons;
    
    std::string surname;
    int age;
    bool sex;
    Student (std::string n, int a, bool c){
        surname = n;
        age = a;
        sex = c;
    }
    Student() : surname("Test"), age(0), sex(0) {};
    
    
};

void add(Student& student, Lesson& lesson )
{
    student.lessons.push_back(&lesson);
    lesson.clas.push_back(&student);
}

void outt( const Lesson& lesson)
{
    for( auto a : lesson.clas)
    {
        std::cout << (*a).surname << std::endl;
    }
    
}

void outt(const  Student& student)
{
     for( auto a : student.lessons)
    {
        std::cout << (*a).name << std::endl;
    }
}

void out_compl(const Student& student)
{
    double av = 0;
    for (int i = 0; i < student.lessons.size(); i++){
        av += (*student.lessons[i]).complexcity;
    }
    av /= student.lessons.size();
    std::cout << av;
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