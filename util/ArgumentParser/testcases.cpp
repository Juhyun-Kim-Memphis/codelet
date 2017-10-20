//
// Created by juhyun on 17. 10. 18.
//

#include <cstring>
#include "catch.hpp"
#include "ArgumentParser.h"


TEST_CASE("TEST #1") {

    int argc = 3;
    char *argv[3];
    argv[0] = (char *) malloc(30);
    strcpy(argv[0], "cmd");

    argv[1] = (char *) malloc(30);
    strcpy(argv[1], "-i");

    argv[2] = (char *) malloc(30);
    strcpy(argv[2], "40");

    ArgumentParser *ap = new ArgumentParser();

    int a;
    //ap->set(&a, 'i');


    REQUIRE(a == 2);
}