#include <gtest/gtest.h>

using namespace std;

static int objCnt = 0;
/* to show exact result, add -fno-elide-constructors cxxflag to g++
 * */

class Product {
public:
    Product() : data(objCnt), ptr(new double) {
        *ptr = 3.3;
        cout << " default ctor "<< data <<endl;
        objCnt++;
    }

    Product(const Product& p) {
        data = objCnt;
        cout << " copy ctor "<< data<<endl;
        objCnt++;
    }

    Product(Product&& p) noexcept {
        data = objCnt;
        cout << " move ctor "<< data<<endl;
        objCnt++;
    }

    Product& operator=(const Product& rhs) {
        data = rhs.data;
        std::cout << "copy assigned\n";
        return *this;
    }

    Product& operator=(Product&& rhs) noexcept {
        data = std::move(rhs.data);
        std::cout << "move assigned\n";
        return *this;
    }

    ~Product() {
        std::cout << "dtor "<<data<<std::endl;
        delete ptr;
    }

    void dump(){
        std::cout<< "Dump result: "<<data<<", "<<*ptr<<endl;
    }

private:
    int data;
    double *ptr;
};

Product makeProduct(){
    Product p;
    return p;
}


TEST(CppSkills, testReturnObj) {
    makeProduct().dump(); /* move ctor is called once. */
}

TEST(CppSkills, testReturnObj2) {
    Product&& rvalRef = makeProduct(); /* move ctor is called once. */
    rvalRef.dump();
}

TEST(CppSkills, testReturnObj3) {
    Product obj(makeProduct()); /* move ctor is called twice. (for makeProduct(), obj) */
    obj.dump();
}

/*
 * let's return
 * */

class Buf {
public:
    Buf() : data(), id(objCnt) {
        std::ostream os (&data);
        os << "Hello world!";
        cout << " default ctor "<< id<<endl;
        objCnt++;
    }

    void addStr(std::string in){
        std::ostream os (&data);
        os << in;
    }

    Buf(Buf&& b) : id(objCnt), data(std::move(b.data)) {
        std::ostream os (&b.data);
        os << std::string("invalid");

        cout << " move ctor "<< id<<endl;
        objCnt++;
    }

    Buf(const Buf& b) : id(objCnt) {
        cout << " copy ctor "<< id<<endl;
        objCnt++;
    }

    ~Buf() {
        std::cout << "dtor "<<id<<std::endl;
    }

    std::stringbuf& getData(){ return data; }
    void dump() const {
        std::cout<<data.str()<<std::endl;
    }

    int id;
private:
//    Buf(const Buf& b) = delete;
//    Buf(Buf&& b) = delete; /* "deleting explicitly" will inhibit invocation of implicit copy ctor */
    std::stringbuf data;
};

Buf makeBuffer(){
    Buf b;
    b.addStr(std::string(" added string"));
    return b;  /* b is implicitly treated as an rvalue in the return statement.*/
} /* makeBuffer() is expression has rvalue of type Buf */

/* do not return local variables by reference, ever. An rvalue reference is still a reference.
 * std::move(expression) doesn't create anything, it simply casts the expression to an xvalue.
 * No objects are copied or moved in the process of evaluating std::move(expression)
 * */

/*
 * caller가 makeBuffer 함수에서 return된 temporary 를 rval_ref로 잡으면(caught)
 * That temporary will have its life extended beyond the rval_ref definition and you can use it as if you had caught it by value.
 * temporary의 생명이 rval_ref의 scope까지 연장된다.
 * */

TEST(CppSkills, testStringbufReturnWithMoveCtor) {
    Buf buf(makeBuffer()); /* move ctor is called twice. (for makebuffer(), buf) */
    std::cout<< buf.getData().str() << std::endl;
}

void takesBuffer(Buf&& in) {
    in.addStr(std::string("dddd2"));
    std::cout<< in.getData().str() <<" "<<in.id<< std::endl;
}

void takesBuffer(Buf in) {
    in.addStr(std::string("dddd3"));
    std::cout<< in.getData().str() <<" "<<in.id<< std::endl;
}

/*
 * 1. takesBuffer(Buf in)
 * 2. takesBuffer(Buf&& in) 이 두함수가 동시에 정의되어 있으면
 * takesBuffer(r-value) 이런 호출은 ambiguous 하다.
 * 차이점: 1은 in을 구성하기 위해 ctor를 호출하기 때문에 in이라는 객체가 또 생기는것이다.
 *      caller가 argument로 l-value를 주었을때 copy ctor가 불린다.
 *      move, copy ctor가 둘다 있으면 copy가 불리고, move만 있으면 호출불가(compile 에러). 둘다 delete되었으면 호출불가.
 * 2는 move ctor를 호출하지 않는다. 2는 lvalue를 argument로 받을 수 없다.
 *
 * */


TEST(CppSkills, testPassBuf) {
    Buf a;
//    takesBuffer(std::move(a));
    takesBuffer(a);
    std::cout<<"~~~"<<std::endl;
//    std::cout<< a.getData().str() << std::endl;
}

/* obj를 argument로 넘기는 3가지 유형
 * 1. caller가 넘겨준 obj 실체를 안 바꾸고 함수내에서 obj의 값만 읽고싶다. func(const Obj &in)
 * 2. caller가 넘겨준 obj 내용을 바꿀것이다. func(Obj &in)
 * 3. caller가 넘겨준 obj 와 똑같은것을 copy해서 그것을 func내부에서 내맘대로 하고싶다. func(Obj in)
 *      이 경우, Obj의 copy ctor가 있어야함.
 * 4. caller가 obj를 즉석해서 만들어주고 넘기는경우 (즉, arg로 xrvalue를 넘기는경우) func(Obj&& in) > func(Obj in)
 *         -> func(Obj in) 를 쓸 경우) Obj의 move ctor가 있을경우 move ctor가 우선적으로 불림.
 *         -> func(Obj&& in) 를 쓰면 move ctor조차 안불림. (따라서 move, copy ctor가 둘다 delete되었더라도 호출 가능)
 *
 * Obj의 copy ctor가 없는상태에서 func(Obj in) 를 호출하려면 func(std::move(arg))이렇게 호출하야함.
 * func(Obj in) 이런 prototype은 진짜 쌔삥 Obj를 원한다는것.
 * */
