#include <iostream>
#include <vector>
#include <cstring>
#include <memory>
#include <gtest/gtest.h>

using namespace std;

class Big{
public:
    char *data;
    char name{};
    int id;
    const int ONE_MEGA_BYTE = 1000000;

public:
    Big(char _name) {
        data = new char[ONE_MEGA_BYTE];
        id = cnt++;
        name = _name;

        cout << "id : " << id << " "
             << "default ctor. addr: " << (void*)data << endl;
        cout << "name : " << name << endl;
    }

    //copy ctor (Deep Copy)
    Big(const Big &other) {
        data = new char[ONE_MEGA_BYTE];
        memcpy(data, other.data, ONE_MEGA_BYTE);
        id = cnt++;
        name = other.name;

        cout << "id : " << id << " "
             << "copy ctor. addr: " << (void*)data << endl;
        cout << "name : " << name << endl;
    }

    Big(Big &&other) noexcept {
        id = other.id;
        data = other.data;
        name = other.name;
        other.data = nullptr;
        cout << id << " move ctor. addr : " << (void *)data << endl;
    }

    Big& operator=(const Big &rhs) {
        if (this != &rhs) {
            delete []data;
            data = new char[ONE_MEGA_BYTE];
            memcpy(data, rhs.data, ONE_MEGA_BYTE);
            name = rhs.name;

            cout << "id : " << id << " "
                 << "assignment operator. addr: " << (void*)data << endl;
            cout << "name : " << name << endl;
        }
        return *this;
    }

    ~Big() {
        cout << "id : " << id << " dtor. addr: " << (void*)data << endl;
        cout << "name : " << name << endl;
        delete[]data;
    }

    static int cnt;
};

int Big::cnt = 1;

void takeBig(Big &b){
    cout<< "[in takeBig] :" << b.id <<"\n";
}

Big& returnBig(){
    Big *res = new Big('n');
    return *res;
}

unique_ptr<Big> returnBig2(){
    return unique_ptr<Big>(new Big('j'));
}


TEST(CppSkills, testMoveSemantics) {
/*    Big b('A');
    takeBig(b);

    {
        Big &a = returnBig();
        std::unique_ptr<Big> p = returnBig2();
        delete &a;
    }
    cout<<"-=-=-=-=-=-=-\n";*/

/*
    Big a{'a'};
    cout << "---------------------------------------------------------" << endl;
    Big b{'b'};
    cout << "---------------------------------------------------------" << endl;

    std::vector<Big> vec;

    vec.push_back(std::move(a));
    cout << "---------------------------------------------------------" << endl;
    vec.push_back(std::move(b));
    cout << "---------------------------------------------------------" << endl;

    for( auto& e : vec) // use auto& rather than auto
        cout << e.name << ", ";
    cout<<"\n\n";
*/
}

/* TODO: returning class object without copy.
 *      case1: returning existing object (e.g. member)
 *      case2: returning newly created object (factory)
 *             In order to invoke dtor at the end of caller scope, how to pass ownership to caller?
 * TODO: what is the best way to return stl container? (return collection)
 * TODO: understand Return Value Optimization (RVO) and how we can ensure(test) this happen. CAN WE TRUST THIS?
 * TODO: understand copy ellision
 * TODO: what is best way to make factory method? use smart pointer and return it?
 * */
