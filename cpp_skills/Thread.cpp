#include <thread>
#include <chrono>
#include <iostream>
#ifdef _WIN32
#include <mingw.mutex.h>
#include <mingw.thread.h>
#endif

#include <gtest/gtest.h>

using namespace std;

class ClassObj {
public:
    ClassObj() : data(new double), id(cnt) {
        cout<<"Ctor of ClassObj("<<id<<") data:"<<data<<endl;
        cnt++;
    }

    ~ClassObj() {
        cout<<"Dtor of ClassObj("<<id<<") data:"<<data<<endl;
        cnt--;
        delete data;
    }

    static int cnt;
private:
    double *data;
    int id;
};

int ClassObj::cnt=0;

void func(ClassObj a){
    ClassObj c;
//    while(1){
//        this_thread::sleep_for(std::chrono::milliseconds(100)); /*DO NOTHING*/
//    }
//    this_thread::sleep_for(std::chrono::seconds(2));
}

void threadMain(void){
    ClassObj a;
    ClassObj b;
    func(a);
}

TEST(CppSkills, testStandardThread) {
    ClassObj::cnt=0;
    std::thread victim(threadMain);
//    this_thread::sleep_for(std::chrono::milliseconds(500));
    EXPECT_EQ(true, victim.joinable());
//    victim.~thread();
//    EXPECT_EQ(false, victim.joinable());
    victim.join();
}
