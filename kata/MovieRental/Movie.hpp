#ifndef CODELET_MOVIE_HPP
#define CODELET_MOVIE_HPP

#include <string>

using namespace std;

class Price;

class Movie {
public:
    static const int CHILDRENS = 2;
    static const int REGULAR = 1;
    static const int NEW_RELEASE = 0;

    Movie(string _title, int _priceCode);

    virtual ~Movie();

    int getPriceCode() const;

    void setPriceCode(int _priceCode) {
//        Movie::_priceCode = _priceCode;
    }

    string getTitle() const {
        return _title;
    }

    virtual double getCharge(int daysRented) const;
    int getFrequentRenterPoints(int daysRented) const;

private:
    string _title;
    Price *price{};
};

class Price {
public:
    Price(int _priceCode) : _priceCode(_priceCode) {}

    int getPriceCode() const { return _priceCode; }

    double getCharge(int daysRented) const {
        double result = 0;
        switch (getPriceCode()) {
            case Movie::REGULAR :
                result += 2;
                if(daysRented > 2)
                    result += (daysRented - 2) * 1.5;
                break;
            case Movie::NEW_RELEASE :
                result += daysRented * 3;
                break;
            case Movie::CHILDRENS :
                result += 1.5;
                if(daysRented > 3)
                    result += (daysRented - 3) * 1.5;
                break;
        }
        return result;
    }

private:
    int _priceCode;
};



#endif //CODELET_MOVIE_HPP
