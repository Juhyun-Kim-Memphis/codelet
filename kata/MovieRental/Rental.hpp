#ifndef CODELET_RENTAL_HPP
#define CODELET_RENTAL_HPP

#include "Movie.hpp"

using namespace std;

class Rental {
public:
    Rental(Movie *_movie, int _daysRented) : _movie(_movie), _daysRented(_daysRented) {}

    const Movie &getMovie() const {
        return *_movie;
    }

    int getDaysRented() const {
        return _daysRented;
    }

    double getCharge() const;
    int getFrequentRenterPoints() const;

private:
    Movie *_movie;
    int _daysRented;
};


#endif //CODELET_RENTAL_HPP
