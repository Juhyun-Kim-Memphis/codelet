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
#include <algorithm>
#include <sstream>


using namespace std;

class ArgumentParser {
public:
    ArgumentParser();

    void init();

    void read(int arc, char **argv);

    void addVar(string varName);

    void rmVar(string varName);

    //testing method
    void test_showAll();

    void set(string key, string val);

    int getInt(string key);

    float getFloat(string key);

    double getDouble(string key);

    string getString(string key);


//    FOR TESTING: ADD A BOOL GETTER
    bool getBool(string key);

//    FOR TESTING: ADD AN OBJECT GETTER
//    template<class T>
//    T getObj(string key);


private:
    //private helpers
    void separate(int argc, char **argv);

    map<string, string> m;
    istringstream sstream;

    template<typename T>
    T getVal(string key, T returnVal);
};

#endif /* ARGUMENTPARSER_H */

