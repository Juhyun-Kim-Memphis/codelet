#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class my_exception : public std::runtime_error {
    std::string msg;
public:
    my_exception(const char *file, int line, const char *func) :
            std::runtime_error(std::string("my_exception")) {
        std::ostringstream o;
        o << file << ":" << line << ": ("<<func<<")";
        msg = o.str();
    }
    ~my_exception() throw() {}
    const char *what() const throw() {
        return msg.c_str();
    }
};

void myFunction2(){
    throw my_exception(__FILE__, __LINE__, __FUNCTION__);
}

TEST(CppSkills, testException) {
    try {
        myFunction2();
    }
    catch (const std::runtime_error &ex) {
        std::cout<< "exception contents is:" << ex.what() << std::endl;
    }
}
