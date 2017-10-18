/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArgumentParser.h
 * Author: hspark
 *
 * Created on 2017년 10월 17일 (화), 오전 8:52
 */

#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <cstdlib>
#include <string>
#include <map>

#include "Variable.h"



//needed only during the testing phase
#include <iostream>
#include <vector>

using namespace std;

class ArgumentParser {    
public:
    ArgumentParser(int argc, char** argv);
    void set(int *varToSet, char key);
    void set(double *varToSet, char key);
    void set(float *varToSet, char key);
    void set(string *varToSet, char key);

private: 
    //private helper methods
    map<char, Variable*> separate(int argc, char** argv);    
    map<char, Variable*> m;
};

#endif /* ARGUMENTPARSER_H */

