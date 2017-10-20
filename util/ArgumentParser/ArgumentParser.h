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
#include <iostream>
#include <vector>

using namespace std;

class ArgumentParser {    
public:
    ArgumentParser();
    void init();
    void read(int arc, char** argv);
    void set(int *varToSet, char key);
    void set(double *varToSet, char key);
    void set(float *varToSet, char key);
    void set(string *varToSet, char key);
    void addVar(string varName);
    void rmVar(string varName);

private: 
    //private helper methods
    map<char, string> separate(int argc, char** argv);
    map<char, string> m;
    vector<string> varList;
    void addDefVar();
};

#endif /* ARGUMENTPARSER_H */

