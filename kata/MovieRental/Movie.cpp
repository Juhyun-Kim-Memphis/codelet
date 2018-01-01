#include <string>
#include <iostream>
#include <gtest/gtest.h>

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

private:
    string _title;
    int _priceCode;
};

class Rental {
public:
    Rental(Movie _movie, int _daysRented) : _movie(_movie), _daysRented(_daysRented) {}

    const Movie &getMovie() const {
        return _movie;
    }

    int getDaysRented() const {
        return _daysRented;
    }

private:
    Movie _movie;
    int _daysRented;
};

class Customer {
public:
    Customer(string _name) : _name(_name), _rentals() {}

    void addRental(Rental arg){
        _rentals.push_back(arg);
    }

    string getName() const {
        return _name;
    }

    string statement() {
        double totalAmount = 0;
        int frequentRenterPoints = 0;
        string result = getName() + ": your rental history\n";
        vector<Rental>::iterator it = _rentals.begin();

        while(it != _rentals.end()){
            double thisAmount = 0;
            Rental each = *it;

            switch (each.getMovie().getPriceCode()) {
                case Movie::REGULAR :
                    thisAmount += 2;
                    if(each.getDaysRented() > 2)
                        thisAmount += (each.getDaysRented() - 2) * 1.5;
                    break;
                case Movie::NEW_RELEASE :
                    thisAmount += each.getDaysRented() * 3;
                    break;
                case Movie::CHILDRENS :
                    thisAmount += 1.5;
                    if(each.getDaysRented() > 3)
                        thisAmount += (each.getDaysRented() - 3) * 1.5;
                    break;
            }

            // point increment by 1.
            frequentRenterPoints++;

            // give bonus if you rent NEW_RELEASE more than two days.
            if((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
                    each.getDaysRented() > 1 )
                frequentRenterPoints++;

            // print out the movie info that currently renting.
            result += "\t" + each.getMovie().getTitle() + "\t" +
                    to_string(thisAmount) + "\n";
            // All accumulated amount
            totalAmount += thisAmount;

            ++it;
        }

        // putter add.
        result += "accumulated amount: " + to_string(totalAmount) + "\n";
        result += "total point: " + to_string(frequentRenterPoints) + "\n";
        return result;
    }

private:
    string _name;
    vector<Rental> _rentals;
};

TEST(MovieRental, test) {
    Customer john(string("john"));
    Movie pororo(string("pororo"), 2);
    Movie her(string("her"), 0);

    john.addRental(Rental(pororo, 3));
    john.addRental(Rental(her, 6));

    cout<< john.statement();
}
