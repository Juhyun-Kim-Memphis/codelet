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
    void addVar(string varName);
    void rmVar(string varName);

    int getInt(string key);
    float getFloat(string key);
    double getDouble(string key);
    string getString(string key);

private: 
    //private helper methods
    map<string, string> separate(int argc, char** argv);
    map<string, string> m;
    vector<string> varList;
    void addDefVar();
};

#endif /* ARGUMENTPARSER_H */

