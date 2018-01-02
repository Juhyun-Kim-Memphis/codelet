#include <gtest/gtest.h>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/for_each.hpp>
#include <typeinfo>
#include <iostream>

int voo(int a){
    return a+1;
}
using boo_type = decltype(voo);

struct functor{
    template<class T>
    void operator()(T*){
        std::cout << typeid(T).name()  << '\n';
    }
};

TEST(CppSkills, testTemplateSkills1){
    namespace mpl = boost::mpl;
    using namespace mpl::placeholders;
    typedef mpl::vector<char, int, float, bool> typelist;
    typedef mpl::push_back<typelist,int>::type typelist2;
    typedef mpl::push_back<typelist,boo_type >::type typelist3;
    typedef mpl::transform<typelist3, boost::add_pointer<_1>>::type ptypelist;
    mpl::for_each<ptypelist>(functor());
}

/*
 * TODO: typelist가 완성되었다는 가정하에 std::map<std::string, boost::any> methodMap; 에 각 method들 넣기
 * 0. typelist에 대해서 for_each돌때 map 넘겨줄수있나?
 * 1. method들은 어떻게 얻어 올것인가? (SFINAE로?)
 *
 * */

/*
 * https://stackoverflow.com/questions/8671287/boostmpl-typelist-function-application
 * https://stackoverflow.com/questions/8304582/how-to-store-functional-objects-with-different-signatures-in-a-container
 *
 * */
