#ifndef CODELET_CUSTOMER_HPP
#define CODELET_CUSTOMER_HPP

#include "Movie.hpp"
#include "Rental.hpp"
#include <vector>

using namespace std;

class Customer {
public:
    Customer(string _name) : _name(_name), _rentals() {}

    void addRental(Rental arg){
        _rentals.push_back(arg);
    }

    string getName() const {
        return _name;
    }

    string statement();

private:
    string _name;
    vector<Rental> _rentals;

};

#endif //CODELET_CUSTOMER_HPP
