#include <gtest/gtest.h>

using namespace std;

class Task;
class Message {};
class Event {};
class DerivedEvent : public Event {};

/* TODO: eventFactory should be method template */
Event *eventFactory(Message m){
    return nullptr;
}

/* TODO: handleEvent should be method template that calls ChildTask::handleEvent(DerivedEvent *ev) */
template <typename DerivedEventType>
void handleEvent(DerivedEventType *ev){

}

class Task {
public:
    virtual void handle(Message m) {
        Event *ev = eventFactory(m);
        handleEvent(ev);
    }
};

///////////////////

/*! The template `has_void_handleEvent_no_args_const<T>` exports a
    boolean constant `value` that is true iff `T` provides
    `void handleEvent() const`

    It also provides `static void eval(T const & t)`, which
    invokes void `T::handleEvent() const` upon `t` if such a public member
    function exists and is a no-op if there is no such member.
*/

template< typename T>
struct has_void_handleEvent_DerivedEvent
{
    /* SFINAE handleEvent-has-correct-sig :) */
    template<typename A>
    static std::true_type test(void (A::*)(DerivedEvent *)) {
        return std::true_type();
    }

    /* SFINAE handleEvent-exists :) */
    template <typename A>
    static decltype(test(&A::handleEvent))
    deducingTypeTF(decltype(&A::handleEvent),void *) {
        /* handleEvent exists. What about sig? */
        typedef decltype(test(&A::handleEvent)) return_type;
        return return_type();
    }

    /* SFINAE game over :( */
    template<typename A>
    static std::false_type deducingTypeTF(...) {
        return std::false_type();
    }

    /* This will be either `std::true_type` or `std::false_type` */
    typedef decltype(deducingTypeTF<T>(nullptr, nullptr)) type;

    static const bool value = type::value; /* Which is it? */

    /*  `eval(T const &,std::true_type)`
        delegates to `T::handleEvent()` when `type` == `std::true_type`
    */
    static void eval(T &t,DerivedEvent *ev, std::true_type) {
        t.handleEvent(ev);
    }
    /* `eval(...)` is a no-op for otherwise unmatched arguments */
    static void eval(...){
        // This output for demo purposes. Delete
        std::cout << "T::handleEvent() not called" << std::endl;
    }

    /* `eval(T const & t)` delegates to :-
        - `eval(t,type()` when `type` == `std::true_type`
        - `eval(...)` otherwise
    */
    static void eval(T &t, DerivedEvent *ev) {
        eval(t,ev,type());
    }
};

class ChildTask : public Task {
public:
    void handleEvent(DerivedEvent *ev) {
        cout<<"handleEvent DerivedEvent actual called."<<endl;
    }
};

class ChildTask2 : public Task {
public:
};

// This is the desired implementation of `void f(T const& val)`
template<class T>
void f(T &val, DerivedEvent *ev) {
    has_void_handleEvent_DerivedEvent<T>::eval(val, ev);
}

TEST(CppSkills, testTemplateMethod) {
    ChildTask *ct = new ChildTask;
    ct->handle(Message());
    DerivedEvent de;

    ChildTask c1;
    std::cout << (has_void_handleEvent_DerivedEvent<ChildTask>::value ?
                  "ChildTask has handleEvent" : "ChildTask does not have handleEvent")
              << std::endl;
    f(c1, &de);

    ChildTask2 c2;
    std::cout << (has_void_handleEvent_DerivedEvent<ChildTask2>::value ?
                  "ChildTask2 has handleEvent" : "ChildTask2 does not have handleEvent")
              << std::endl;
    f(c2, &de);
}
