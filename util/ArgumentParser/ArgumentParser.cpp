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
    this->m["test_string"] = "this is a test string";
    this->m["test_int"] = "12345";
    this->m["test_float"] = "0.0001";
    this->m["test_double"] = "1.111111111111";
}

/**
 * Read method that passes actual arguments from the commandline to separate() method.
 * @param argc count of the argument from the command line
 * @param argv value(s) of the arguments from the command line
 */
void ArgumentParser::read(int argc, char **argv) {
    //Read from commandline, separate variables, populate the map
    this->m = separate(argc, argv);
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


void ArgumentParser::test_iterate() {
    ///change this to iterate through the map
    for (map<string, string>::iterator it = this->m.begin(); it != this->m.end(); it++) {
        cout << it->first << ": " << it->second;
        if (it != prev(this->m.end())) {
            cout << ", ";
        }
    }
    cout << endl;
}

map<string, string> ArgumentParser::separate(int argc, char **argv) {

    //map for key & variable pairs
    map<string, string> m;

    //local loop counter
    int i = 1;

    //Loop for all elements in argv, starts at 1 since program path is at the 0'th index
    LOOLOOPY_LOOLOOPANG:
    do {
        //looking for keywords in each string
        if (argv[i][0] == '-') {

            string str(argv[i]);

            //FIND whether argv[i] exists in the map.
            //if found: put the value in the map
            //if not: print out error, then skip to the next element
            if (this->m.find(str) == m.end()) {
                cout << "[ERROR]NO SUCH VARIABLE: \"" << argv[i][1] << "\" " << endl;
                //skip to the next variable
                i++;
                goto LOOLOOPY_LOOLOOPANG;

            }
            //CORNER CASE CHECK : for boolean variable
            //check if the following string is another keyword
            if (argv[i + 1][0] == '-') {
                this->m[str] = "TRUE";
            } else {
                this->m[str] = argv[++i];
            }
        }
        //increment the loop counter
        i++;
    } while (i < argc);

    //return the fucking map with shits in it
    return m;
}
//
///**
// *
// * @param varToSet pointer of the variable to be set with the value returned from the command line argument
// * @param key should match one of the key values from separate method's switch.
// * @return value to be set to the input variable
// */
//void ArgumentParser::set(int *varToSet, char key) {
//    if (this->m.find(key) == this->m.end()) {
//        cout << "No such key exists you moron, check and try again" << endl;
//    } else {
//        *varToSet = ((IntVariable *)(this->m[key]))->getVal();
//    }
//}
//
//void ArgumentParser::set(double *varToSet, char key) {
//    if (this->m.find(key) == this->m.end()) {
//        cout << "No such key exists you moron, check and try again" << endl;
//    } else {
//        *varToSet = ((DoubleVariable *)(this->m[key]))->getVal();
//    }
//}
//
//void ArgumentParser::set(float *varToSet, char key) {
//    if (this->m.find(key) == this->m.end()) {
//        cout << "No such key exists you moron, check and try again" << endl;
//    } else {
//        *varToSet = ((FloatVariable *)(this->m[key]))->getVal();
//    }
//}
//
//void ArgumentParser::set(string *varToSet, char key) {
//    if (this->m.find(key) == this->m.end()) {
//        cout << "No such key exists you moron, check and try again" << endl;
//    } else {
//        *varToSet = ((StringVariable *)(this->m[key]))->getVal();
//    }
//}
