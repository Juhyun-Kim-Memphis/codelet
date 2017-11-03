#include <iostream>

using namespace std;

/* Simple builder. pass pointer */
class Human {
public:
    static Human &make(){
        return *(new Human);
    }

    Human &setName(string n){
        name.assign(n);
        return *this;
    }
    
    Human &setGrade(int g){
        grade = g;
        return *this;
    }
    
    Human &setAge(int a){
        age = a;
        return *this;
    }

    void printInfo(){
        cout <<"name:" << name << ", grade:" << grade << ", age:" << age <<"\n";
    }

private:
    Human(){};
    string name;
    int grade;
    int age;
};

int main(int argc, char const *argv[])
{
    Human &bob = Human::make().setName("bob").setGrade(1).setAge(25);
    bob.printInfo();

    return 0;
}