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

ArgumentParser::ArgumentParser(int argc, char** argv) {
    //At the construction of the object, populate the map
    this->m = separate(argc, argv);
}

map<char, Variable*> ArgumentParser::separate(int argc, char** argv) {

    //map for key & variable pairs
    map<char, Variable*> m;

    //Loop for all elements in argv, starts at 1 since program path is at 0 index
    for (int i = 1; i < argc; i++) {
        //looking for "-*" combination in each string
        if (argv[i][0] == '-' && argv[i][2] == NULL) {
            //FIND whether [i][1] exists in the map, if found put the value, if not, send back error
            //ASSUMES that only one string following the key is the value to put
            switch (argv[i][1]) {
                case 's':
                    m['s'] = new StringVariable(argv[++i]);

                case 'f':
                    //float will be implicitly converted (hopefully)
                    m['f'] = new FloatVariable(atof(argv[++i]));

                case 'd':
                    m['d'] = new DoubleVariable(atof(argv[++i]));

                case 'i':
                    m['i'] = new IntVariable(atoi(argv[++i]));

                default:
                    //none of the case matches - no such key exists
                    cout << "NO SUCH VARIABLE: \"" << argv[i][1] << "\" " << endl;
                    cout << "USE -i, -f, -d, or -s" << endl;
                            //no exception handling at the moment
            }
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
