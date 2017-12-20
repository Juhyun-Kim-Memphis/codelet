#include <gtest/gtest.h>

using namespace std;

class Product {
public:
    Product() : data(1), ptr(new double[200]) {
        cout << " default ctor "<<endl;
    }

    Product(const Product& p) {
        cout << " copy ctor "<<endl;
    }

    Product(Product&& p) noexcept {
        cout << " move ctor "<<endl;
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
        std::cout << "dtor\n";
    }

    void dump(){}

private:
    int data;
    double *ptr;
};

Product makeProduct(){
    return Product();
}

TEST(CppSkills, testReturnObj) {
    Product p(makeProduct());
    p.dump();
}
