//
// Created by juhyun on 17. 10. 18.
//

#include <cstring>
#include "catch.hpp"
#include "ArgumentParser.h"


TEST_CASE("test module insert and Default IParam value of modules") {
    int argc = 3;
    char *argv[3];
    argv[0] = (char *)malloc(30);
    strcpy(argv[0], "cmd");

    argv[1] = (char *)malloc(30);
    strcpy(argv[1], "-i");

    argv[2] = (char *)malloc(30);
    strcpy(argv[2], "40");

    ArgumentParser argumentParser("i#");

    int a;
    a = argumentParser.set('i');

    REQUIRE(a == 30);
}