#include <iostream>
#include <vector>
#include <cstring>
#include <gtest/gtest.h>

using namespace std;

class Big{
public:
    char *data;
    char name{};
    int id;

public:
    Big(char _name) {
        data = new char[1000000];
        id = cnt++;
        name = _name;

        cout << "id : " << id << " "
             << "default ctor. addr: " << (void*)data << endl;
        cout << "name : " << name << endl;
    }

    //copy ctor (Deep Copy)
    Big(const Big &other) {
        data = new char[1000000];
        memcpy(data, other.data, 1000000);
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
            data = new char[1000000];
            memcpy(data, rhs.data, 1000000);
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

TEST(TaskGoF, testMoveSemantics) {
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
}