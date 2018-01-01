#include <string>
#include "Movie.hpp"

using namespace std;

Movie::Movie(string _title, int _priceCode) : _title(_title) {
    price = new Price(_priceCode);
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


