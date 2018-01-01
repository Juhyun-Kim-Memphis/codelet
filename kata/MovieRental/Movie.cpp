#include <string>
#include <iostream>
#include "Movie.hpp"

using namespace std;

Movie::Movie(string _title, int _priceCode) : _title(_title), price(nullptr) {
    setPriceCode(_priceCode);
}

Movie::~Movie() {
    delete price;
}

int Movie::getPriceCode() const {
    return price->getPriceCode();
}

double Movie::getCharge(int daysRented) const {
    return price->getCharge(daysRented);
}

int Movie::getFrequentRenterPoints(int daysRented) const {
    // give bonus if you rent NEW_RELEASE more than two days.
    if((getPriceCode() == Movie::NEW_RELEASE) &&
       daysRented > 1 )
        return 2;
    else
        return 1;
}

void Movie::setPriceCode(int _priceCode) {
    if(price)
        delete price;

    switch (_priceCode) {
        case Movie::REGULAR :
            price = new RegularPrice;
            break;
        case Movie::NEW_RELEASE :
            price = new NewReleasePrice;
            break;
        case Movie::CHILDRENS :
            price = new ChildrensPrice;
            break;
        default:
            throw string("Illegal price code for movie\n");
    }
}


