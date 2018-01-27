#include <gtest/gtest.h>

/* TO study: https://stackoverflow.com/questions/13980157/c-class-with-template-member-variable */
/* http://timmurphy.org/2014/08/28/passing-member-functions-as-template-parameters-in-c/
 * https://stackoverflow.com/questions/13385397/static-member-function-pointer-as-template-argument
 * https://stackoverflow.com/questions/1174169/function-passed-as-template-argument
 * */
void bar(){
    std::cout<<"bar"<<std::endl;
}

template <class T>
struct Base
{
    void interface()
    {
        // ...
        static_cast<T*>(this)->func();
        // ...
    }
    template <typename FUNC> void methodCall(FUNC f);
    template <typename FUNC> void staticMemberCall(FUNC f);
};

class ClsA : public Base<ClsA> {
public:
    static void func() {
        std::cout<<"ClsA: func"<<std::endl;
    }

    void method() {
        std::cout<<"ClsA: method"<<std::endl;
    }
};

template <class T>
template <typename FUNC>
void Base<T>::methodCall(FUNC f) {
    T* t = static_cast<T*>(this);
    (t->*f)();
}

template<class T>
template<typename FUNC>
void Base<T>::staticMemberCall(FUNC f) {
    f();
}


TEST(CppSkills, testClassTemplate) {
    ClsA *a = new ClsA;
    a->interface();
    a->methodCall(&ClsA::method);
    a->method();
    a->staticMemberCall(ClsA::func);
}

//class IClsB {
//public:
//    virtual int foo(int a) = 0;
//};
//
//class ClsB : public IClsB {
//public:
//    int foo(int a) override {
//        std::cout<<"ClsB: foo"<<std::endl;
//        return 1;
//    }
//};