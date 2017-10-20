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
    //read from commandline, populate the map
    this->m = separate(argc, argv);
}

void ArgumentParser::init(){
    //populate the map first

    //1. add hard coded lists of variables to the map
    this->varList.clear();
    this->addDefVar();


}

void ArgumentParser::addDefVar() {
    this->varList.push_back("a");
    this->varList.push_back("b");
    this->varList.push_back("c");

    vector<string>::iterator it;
    for (it = this->varList.begin(); it != this->varList.end(); it++){

    }

}


//1. add : read from command line (so the constructor does not take params
//2. mod : set -> simply return
//3. mod :

map<char, string> ArgumentParser::separate(int argc, char** argv) {

    //map for key & variable pairs
    map<char, string> m;

    //Loop for all elements in argv, starts at 1 since program path is at 0 index
    for (int i = 1; i < argc; i++) {
        //looking for "-*" combination in each string
        if (argv[i][0] == '-' && argv[i][2] == NULL) {
            //FIND whether [i][1] exists in the map, if found put the value, if not, send back error
            //ASSUMES that only one string following the key is the value to put
            m[(argv[i][1])] = argv[++i];

//                    //none of the case matches - no such key exists
//                    cout << "NO SUCH VARIABLE: \"" << argv[i][1] << "\" " << endl;
//                    cout << "USE -i, -f, -d, or -s" << endl;
//                            //no exception handling at the moment

        }
    }

    return m;
}

/**
 * 
 * @param varToSet pointer of the variable to be set with the value returned from the command line argument
 * @param key should match one of the key values from separate method's switch.
 * @return value to be set to the input variable
 */
void ArgumentParser::set(int *varToSet, char key) {
    if (this->m.find(key) == this->m.end()) {
        cout << "No such key exists you moron, check and try again" << endl;
    } else {
        *varToSet = ((IntVariable *)(this->m[key]))->getVal();
    }
}

void ArgumentParser::set(double *varToSet, char key) {
    if (this->m.find(key) == this->m.end()) {
        cout << "No such key exists you moron, check and try again" << endl;
    } else {
        *varToSet = ((DoubleVariable *)(this->m[key]))->getVal();
    }
}

void ArgumentParser::set(float *varToSet, char key) {
    if (this->m.find(key) == this->m.end()) {
        cout << "No such key exists you moron, check and try again" << endl;
    } else {
        *varToSet = ((FloatVariable *)(this->m[key]))->getVal();
    }
}

void ArgumentParser::set(string *varToSet, char key) {
    if (this->m.find(key) == this->m.end()) {
        cout << "No such key exists you moron, check and try again" << endl;
    } else {
        *varToSet = ((StringVariable *)(this->m[key]))->getVal();
    }
}
