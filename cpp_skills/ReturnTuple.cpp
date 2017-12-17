
#include <gtest/gtest.h>

class Foo {
public:
    Foo() {}
    Foo(int a, double b) : a(a), b(b) {}
    Foo(const Foo &f) : a(f.a), b(f.b) {
        //std::cout<<"cpy ctr called."<<b<<"\n";
    } // not necessary.

    // TODO : make move ctor, move assignment op.
    /*Foo(Foo &&f) noexcept : a(f.a), b(f.b)  {
        //std::cout<<"mv ctr called."<<b<<"\n";
    }*/

    bool operator==(const Foo &rhs) const {
        return a == rhs.a &&
               b == rhs.b;
    }

    bool operator!=(const Foo &rhs) const {
        return !(rhs == *this);
    }

    int a;
    double b;
};

std::tuple<int, std::string, Foo, std::vector<int>> returnTuple() {
    // move ctor Foo is called here std::make_tuple.
    return std::make_tuple(3, "hello", Foo(1, 3.0), std::vector<int>({1, 2}));
};

std::tuple<int, std::string, Foo, std::vector<int>> returnTupleAsInitList() {
    return {3, "hello", Foo(1, 3.0), {1, 2}}; // Error until C++17 ?
};

TEST(CppSkills, testReturnTuple) {
    /* warning: Copy ctor is invoked many times. */
    EXPECT_EQ(std::make_tuple(3, "hello", Foo(1, 3.0), std::vector<int>({1, 2})), returnTuple());
    EXPECT_EQ(std::make_tuple(3, "hello", Foo(1, 3.0), std::vector<int>({1, 2})), returnTupleAsInitList());
    EXPECT_EQ(returnTuple(), returnTupleAsInitList());

    auto res = returnTuple();
    EXPECT_EQ(3, std::get<0>(res));
    EXPECT_EQ("hello", std::get<1>(res));
    EXPECT_EQ(Foo(1, 3.0), std::get<2>(res));
    EXPECT_EQ(std::vector<int>({1, 2}), std::get<3>(res));

    int fst;
    std::string snd;
    Foo trd;
    std::vector<int> fth;
    std::tie(fst, snd, trd, fth) = returnTupleAsInitList();
    EXPECT_EQ(3, fst);
    EXPECT_EQ("hello", snd);
    EXPECT_EQ(Foo(1, 3.0), trd);
    EXPECT_EQ(std::vector<int>({1, 2}), fth);
}