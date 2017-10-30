/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArgumentParser.cpp
 * Author: hspark
 * 
 * Created on 2017년 10월 17일 (화), 오전 8:52
 */

#include "ArgumentParser.h"

/**
 * One and only default constructor. Simply calls the intializer.
 */
ArgumentParser::ArgumentParser() {
    //empty constructor
    this->init();
}

/**
 * Initializer for the class. Clears out the pre-existing variable map
 * then repopulate the map with default variables
 */
void ArgumentParser::init() {
    this->m.clear();
    //this->m["test_string"] = "this is a test string";
    //this->m["test_int"] = "12345";
    //this->m["test_float"] = "0.0001";
    //this->m["test_double"] = "1.111111111111";
}

/**
 * Read method that passes actual arguments from the commandline to separate() method.
 * @param argc count of the argument from the command line
 * @param argv value(s) of the arguments from the command line
 */
void ArgumentParser::read(int argc, char **argv) {
    //Read from commandline, separate variables, populate the map
    this->separate(argc, argv);
}

/**
 * Setter for the variable. Set the value of a variable on runtime
 * @param key name of the variable
 * @param val value for the variable
 */
void ArgumentParser::set(string key, string val) {
    //Check if the variable exists, if not, print out an error message.
    if (this->m.find(key) == m.end()) {
        cout << "[ERROR]NO SUCH VARIABLE: \"" << key << "\" " << endl;
    } else {
        //if the variable exists, set the value for the variable
        this->m[key] = val;
    }
}

/**
 * Add a variable on runtime
 * @param varName name of the variable
 */
void ArgumentParser::addVar(string varName) {
    //If the variable with the same name does not exist
    if (this->m.find(varName) == this->m.end()) {
        //add the element to the map with a default value of blank.
        (this->m)[varName] = "";
    } else {
        //If the variable already exists in the map, print out an error message
        cout << "[ERROR]VARIABLE: \"" << varName << "\" ALREADY EXISTS" << endl;
    }
}

/**
 * Remove a variable on runtime
 * @param varName
 */
void ArgumentParser::rmVar(string varName) {
    //remove the element from the map
    (this->m).erase(varName);
}

//IT IS QUESTIONABLE WHETHER THIS METHOD WOULD BE REQUIRED OR NOT
void ArgumentParser::test_showAll() {
    for (map<string, string>::iterator it = this->m.begin(); it != this->m.end(); it++) {
        string val;
        if (it->second == "") {
            val = "N/A";
        } else {
            val = it->second;
        }
        cout << it->first << ": " << val;
        if (it != prev(this->m.end())) {
            cout << ", ";
        }
    }
    cout << endl;
}

/**
 * Most critical function of this application, gets the arguments; separates them; store them appropriately into the map.
 * @param argc number of arguments passed
 * @param argv value of the arguments
 * @return fully populated map
 */
void ArgumentParser::separate(int argc, char **argv) {
    //local loop counter
    int i = 1;

    //Loop for all elements in argv, starts at 1 since program path is at the 0'th index
    do {
        //looking for keywords in each string
        if (argv[i][0] == '-') {

            //Getting the variable name string without the hyphen deliminator
            string str(argv[i]);
            str = str.substr(1, str.length());

            //CORNER CASE CHECK : for boolean variable
            //check if the following string is another keyword
            if (i + 1 == argc || argv[i + 1][0] == '-') {
                this->m[str] = "1";
            } else {
                this->m[str] = argv[++i];
            }
        }
        //increment the loop counter
        i++;
    } while (i < argc);
}

/**
 * Conversion method for string value to desired output value
 * @tparam T
 * @param key
 * @param returnVal
 * @return
 */
template<typename T>
T ArgumentParser::getVal(string key, T returnVal) {
    //If the key does not exist, print out a VERY RUDE error message.
    if (this->m.find(key) == this->m.end()) {
        cout << "No such key exists you moron, check and try again" << endl;
    } else {
        //clear the stream first
        this->sstream.clear();
        //try string conversion
        this->sstream.str(this->m[key]);
        istringstream(this->m[key]);

        if (!(this->sstream >> returnVal)) {
            cout << "[ERROR]CONVERSION FAILED WITH : " << "\"" << this->m[key] << "\"" << endl;
        } else {
            return returnVal;
        }
    }
}

int ArgumentParser::getInt(string key) {
    //Value to return
    int returnVal;
    return this->getVal(key, returnVal);
}

float ArgumentParser::getFloat(string key) {
    //Value to return
    float returnVal;
    return this->getVal(key, returnVal);
}

double ArgumentParser::getDouble(string key) {
    //Value to return
    double returnVal;
    return this->getVal(key, returnVal);
}

//Not really need to go through the conversion for the string as all the values are already stored as strings
string ArgumentParser::getString(string key) {
    //Value to return
    string returnVal;
    return this->getVal(key, returnVal);
}

bool ArgumentParser::getBool(string key) {
    //Value to return
    bool returnVal;
    return this->getVal(key, returnVal);
}

//template<typename T>
//T ArgumentParser::getObj(string key) {
//    T returnVal;
//    return this->getVal(key, returnVal);
//}