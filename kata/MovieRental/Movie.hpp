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

    void setPriceCode(int _priceCode);

    string getTitle() const {
        return _title;
    }

    double getCharge(int daysRented) const;
    int getFrequentRenterPoints(int daysRented) const;

private:
    string _title;
    Price *price;
};

class Price {
public:
    virtual int getPriceCode() const = 0;
    virtual double getCharge(int daysRented) const = 0;

    virtual ~Price() {

    }

    virtual int getFrequentRenterPoints(int daysRented){
        return 1;
    }
};

class ChildrensPrice : public Price {
public:
    int getPriceCode() const override { return Movie::CHILDRENS; }

    double getCharge(int daysRented) const override {
        double result = 0;
        result += 1.5;
        if(daysRented > 3)
            result += (daysRented - 3) * 1.5;
        return result;
    }
};

class RegularPrice : public Price {
public:
    int getPriceCode() const override { return Movie::REGULAR; }

    double getCharge(int daysRented) const override {
        double result = 0;
        result += 2;
        if(daysRented > 2)
            result += (daysRented - 2) * 1.5;
        return result;
    }
};

class NewReleasePrice : public Price {
public:
    int getPriceCode() const override { return Movie::NEW_RELEASE; }

    double getCharge(int daysRented) const override {
        return daysRented * 3;
    }

    int getFrequentRenterPoints(int daysRented) override {
        return daysRented > 1 ? 2 : Price::getFrequentRenterPoints(daysRented);
    }
};




#endif //CODELET_MOVIE_HPP
