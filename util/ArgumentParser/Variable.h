/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.h
 * Author: hspark
 *
 * Created on 2017년 10월 17일 (화), 오후 12:48
 */

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

using namespace std;

class Variable {
};

class IntVariable: public Variable {
public:
    IntVariable(int in);
    int getVal();
private:
    int value;
};

class DoubleVariable: public Variable {
public:
    DoubleVariable(double in);
    double getVal();
private:
    double value;
};

class FloatVariable: public Variable {
public:
    FloatVariable(float in);
    float getVal();
private:
    float value;
};

class StringVariable: public Variable {
public:
    StringVariable(string in);
    string getVal();
private:
    string value;
};

#endif /* VARIABLE_H */

