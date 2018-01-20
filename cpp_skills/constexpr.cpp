#include <gtest/gtest.h>

class GreetingMessage {
public:
    static constexpr int id = 1;
};


TEST(CppSkills, testConstexpr) {
    std::cout<<"GUID is "<<GreetingMessage::id<<std::endl;
}
