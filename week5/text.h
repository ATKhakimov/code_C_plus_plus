#pragma once
#include <iostream>
#include <vector>


class Student;
class Lesson;

class Lesson
{
public:
    Lesson() : name("Test1"), amount(0), complexcity(0){};
    Lesson (const std::string n, int a, int c): n {name}, a {amount}, c {complexcity}{
      
    };
    ~Lesson() = default;
    std::vector<Student*> clas;
    std::string name;   
    int amount;
    int complexcity;
    void outCompexcity() const
    {
        std::cout << "complexcity" << " " << name <<" is" << complexcity;
    }
    
private:
    int teacher_age;
    
};

class Student
{
public:
    Student (const std::string n, int a, bool c) : n {surname}, a{age}, c{sex}
    {
       
    }
    Student() : surname("Test"), age(0), sex(0) {};
    ~Student() = default;
    std::vector<Lesson*> lessons;
    std::string surname;
    int age;
    bool sex;
    
private:
    int student_criminal;
    
};

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


void add(Student& student, Lesson& lesson )
{
    student.lessons.push_back(&lesson);
    lesson.clas.push_back(&student);
}



