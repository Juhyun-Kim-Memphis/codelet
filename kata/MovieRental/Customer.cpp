//
// Created by user on 2018-01-01.
//

#include "Customer.hpp"

string Customer::statement() {
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    string result = getName() + ": your rental history\n";
    vector<Rental>::iterator it = _rentals.begin();

    while(it != _rentals.end()){
        double thisAmount = 0;
        Rental each = *it;

        thisAmount = amountFor(each);

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

double Customer::amountFor(const Rental &each) const {
    double result = 0;
    switch (each.getMovie().getPriceCode()) {
            case Movie::REGULAR :
                result += 2;
                if(each.getDaysRented() > 2)
                    result += (each.getDaysRented() - 2) * 1.5;
                break;
            case Movie::NEW_RELEASE :
                result += each.getDaysRented() * 3;
                break;
            case Movie::CHILDRENS :
                result += 1.5;
                if(each.getDaysRented() > 3)
                    result += (each.getDaysRented() - 3) * 1.5;
                break;
        }
    return result;
}
