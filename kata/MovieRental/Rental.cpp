//
// Created by user on 2018-01-01.
//

#include "Rental.hpp"

double Rental::getCharge() const {
    double result = 0;
    switch (getMovie().getPriceCode()) {
        case Movie::REGULAR :
            result += 2;
            if(getDaysRented() > 2)
                result += (getDaysRented() - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE :
            result += getDaysRented() * 3;
            break;
        case Movie::CHILDRENS :
            result += 1.5;
            if(getDaysRented() > 3)
                result += (getDaysRented() - 3) * 1.5;
            break;
    }
    return result;
}

int Rental::getFrequentRenterPoints() const {
    // give bonus if you rent NEW_RELEASE more than two days.
    if((getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
       getDaysRented() > 1 )
        return 2;
    else
        return 1;
}