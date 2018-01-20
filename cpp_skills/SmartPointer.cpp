#include <gtest/gtest.h>

class Fooo {
public:
    Fooo() : a(1) {}

    ~Fooo() {
        std::cout<<" ~Fooo"<<std::endl;
    }

    int a;
};

TEST(CppSkills, unique_ptr_raii) {
    Fooo *raw = new Fooo;
    std::unique_ptr<Fooo> foo(raw);
}


TEST(CppSkills, unique_ptr_raii_throw) {
    Fooo *raw = new Fooo;


    try {
        std::unique_ptr<Fooo> foo(raw);
        throw std::exception();
    } catch (const std::exception &e) {
        std::cout<<" catch block"<<std::endl;
    }

    std::cout<<" after try block"<<std::endl;

}