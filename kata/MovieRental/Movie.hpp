#ifndef CODELET_MOVIE_HPP
#define CODELET_MOVIE_HPP

#include <string>

using namespace std;

class Movie {
public:
    static const int CHILDRENS = 2;
    static const int REGULAR = 1;
    static const int NEW_RELEASE = 0;

    Movie(string _title, int _priceCode) : _title(_title), _priceCode(_priceCode) {}

    int getPriceCode() const {
        return _priceCode;
    }

    void setPriceCode(int _priceCode) {
        Movie::_priceCode = _priceCode;
    }

    string getTitle() const {
        return _title;
    }

    double getCharge(int daysRented) const;
    int getFrequentRenterPoints(int daysRented) const;

private:
    string _title;
    int _priceCode;
};

#endif //CODELET_MOVIE_HPP
