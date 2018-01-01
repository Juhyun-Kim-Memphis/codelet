//
// Created by user on 2018-01-01.
//

#include "Customer.hpp"

string Customer::statement() {
    string result = getName() + ": your rental history\n";
    vector<Rental>::iterator it = _rentals.begin();

    while(it != _rentals.end()){
        Rental each = *it;
        // print out the movie info that currently renting.
        result += "\t" + each.getMovie().getTitle() + "\t" +
                  to_string(each.getCharge()) + "\n";
        ++it;
    }

    // putter add.
    result += "accumulated amount: " + to_string(getTotalCharge()) + "\n";
    result += "total point: " + to_string(getTotalFrequentRenterPoints()) + "\n";
    return result;
}

double Customer::getTotalCharge() const {
    double result = 0;
    vector<Rental>::const_iterator it = _rentals.begin();
    while(it != _rentals.end()){
        Rental each = *it;
        result += each.getCharge();
        ++it;
    }
    return result;
}

int Customer::getTotalFrequentRenterPoints() const {
    int result = 0;
    vector<Rental>::const_iterator it = _rentals.begin();
    while(it != _rentals.end()){
        Rental each = *it;
        result += each.getFrequentRenterPoints();
        ++it;
    }
    return result;
}

