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

ArgumentParser::ArgumentParser() {
    //empty constructor
}

void ArgumentParser::read(int argc, char **argv) {
    //Read from commandline, separate variables, populate the map
    this->m = separate(argc, argv);
}

void ArgumentParser::init() {
    //Clear the variable list
    this->varList.clear();
    //Populate the map with hard coded lists of variables
    this->addDefVar();
}

void ArgumentParser::addVar(string varName){
    //add the element to the vector
    this->varList.push_back(varName);
    //add the element to the map
    (this->m)[varName] = "";
}

void ArgumentParser::rmVar(string varName){
    //remove the element from the vector
    //
    //NEEDS TO VERIFY IF THIS WORKS OR I SHOULD ITERATE THROUGH THE FUCKING VECTOR FOR LINEAR SEARCH AND DELETE
    //
    this->varList.erase(remove(varList.begin(), varList.end(), varName), varList.end());
    //remove the element from the map
    (this->m).erase(varName);
}

void ArgumentParser::addDefVar() {
    //For default variables, variable names must be HARD CODED HERE
    this->varList.push_back("test_a");
    this->varList.push_back("test_b");
    this->varList.push_back("test_c");

    vector<string>::iterator it;
    for (it = this->varList.begin(); it != this->varList.end(); it++) {
        //put empty values for now
        //if the default variable needs default values, it needs to be HARD CODED HERE
        this->m[*it] = "";
    }
}


//1. add : read from command line (so the constructor does not take params
//2. mod : set -> simply return
//3. mod :

map<string, string> ArgumentParser::separate(int argc, char **argv) {

    //map for key & variable pairs
    map<string, string> m;

    //local loop counter
    int i = 1;

    //Loop for all elements in argv, starts at 1 since program path is at the 0'th index
    LOOP:
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
                goto LOOP;

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
