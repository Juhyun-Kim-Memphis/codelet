//
// Created by juhyun on 17. 10. 18.
//

#include <cstring>
#include "catch.hpp"
#include "ArgumentParser.h"

//Object initialization test
TEST_CASE("TEST #1: CAN IT BE INITIALIZED?") {

    //Create a dummy commandline arguments
    int argc = 3;
    char *argv[3];
    argv[0] = (char *) malloc(30);
    strcpy(argv[0], "cmd");

    argv[1] = (char *) malloc(30);
    strcpy(argv[1], "-i");

    argv[2] = (char *) malloc(30);
    strcpy(argv[2], "40");


    ArgumentParser *ap = new ArgumentParser();


    //int a = ap->getInt("i");

    //REQUIRE(a == 40);
}


//addVar & rmVar test
TEST_CASE("TEST #2: CAN IT PRINT VARIABLE NAMES FROM THE VARIABLE LIST?") {
    ArgumentParser *ap = new ArgumentParser();

    ap->addVar("a");
    ap->addVar("b");
    ap->addVar("c");
    ap->addVar("d");

    ap->test_iterate();

    ap->rmVar("b");
    ap->rmVar("c");

    ap->test_iterate();

    REQUIRE(1 == 1);

}