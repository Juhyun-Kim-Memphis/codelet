/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.cpp
 * Author: hspark
 * 
 * Created on 2017년 10월 17일 (화), 오후 12:48
 */

#include "Variable.h"
#include <string>

using namespace std;

IntVariable::IntVariable(int in){
    this->value = in;
};

int IntVariable::getVal(){
    return this->value;
}

DoubleVariable::DoubleVariable(double in){
    this->value = in;
};

double DoubleVariable::getVal(){
    return this->value;
};

FloatVariable::FloatVariable(float in){
    this->value = in;
};

float FloatVariable::getVal(){
    return this->value;
}

StringVariable::StringVariable(string in){
    this->value = in;
};

string StringVariable::getVal(){
    return this->value;
}

