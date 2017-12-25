#include <type_traits>
#include <utility>
#include <gtest/gtest.h>

using namespace std;

class Foo{
public:
    int *test(double x, double y){ return nullptr; }
    double *test(int x, int y){ return nullptr; }
    char *test(char x, int y){ return nullptr; }
};

int test(double x, double y);
double test(int x, int y);
char* test(char x, int y);

template<typename... Ts>
using TestType = decltype(test(std::declval<Ts>()...))(Ts...);

template<typename C, typename... Ts>
using MethodType = decltype(std::declval<C>().test(std::declval<Ts>()...))(Ts...);

TEST(CppSkills, Decltype) {
    static_assert(std::is_same<TestType<double, double>, int(double, double)>::value, "1");
    static_assert(std::is_same<TestType<int, int>, double(int, int)>::value, "2");
    static_assert(std::is_same<TestType<char, int>, char*(char, int)>::value, "3");
    static_assert(std::is_same<MethodType<Foo, char, int>, char*(char, int)>::value, "4");

    Foo f;
    f.test('s', 2);

    std::cout << "is: " << typeid(TestType<char, int>).name() << '\n';
    std::cout << "is: " << typeid(MethodType<Foo, char, int>).name() << '\n';
}
