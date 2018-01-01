#include "Rental.hpp"

double Rental::getCharge() const {
    return _movie.getCharge(getDaysRented());
}

int Rental::getFrequentRenterPoints() const {
    return _movie.getFrequentRenterPoints(getDaysRented());
}