#include <iostream>

using namespace std;

class Mood {
public:
    virtual void express() = 0;
};

class Angry : public Mood {
    void express () override {
        cout << "SHIT!!!\n";
    }
};

class Happy : public Mood {
    void express () override {
        cout << "HaHa!!!\n";
    }
};

/* Simple builder. pass pointer */
class Human {
public:
    Human(){
        // myMood = new Angry;
        flag = 0;
    };

    void speak(){
        if(flag == 0){
            cout << "HaHa!!!\n";
            flag = 1;
        }
        else if (flag == 1){
            cout << "SHIT!!!\n";
        }
    }

private:
    int flag;
    // Mood *myMood;
};

int main(int argc, char const *argv[])
{
    Human bob;
    bob.speak();
    bob.speak();

    return 0;
}