//
// Created by juhyun on 17. 10. 18.
//

#include <cstring>
#include "catch.hpp"
#include "ArgumentParser.h"

//Object initialization test
TEST_CASE("TEST #1: CAN IT BE INITIALIZED?") {
    cout << "\n***START OF TEST #1" << endl;
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
    ap->read(argc, argv);
    ap->test_showAll();

    int a = ap->getInt("i");

    REQUIRE(a == 40);
    cout << "***END OF TEST #1" << endl;
}


//addVar & rmVar test
TEST_CASE("TEST #2: CAN IT PRINT CONTENTS OF THE VARIABLE MAP?") {
    cout << "\n***START OF TEST #2" << endl;
    ArgumentParser *ap = new ArgumentParser();

    ap->addVar("a");
    ap->addVar("b");
    ap->addVar("c");
    ap->addVar("d");

    ap->test_showAll();

    ap->rmVar("b");
    ap->rmVar("c");

    ap->test_showAll();

    REQUIRE(1 == 1);
    cout << "***END OF TEST #2" << endl;
}

//응?
TEST_CASE("TEST #3: DOES ALL BASIC GET FUNCTIONS WORK?") {
    cout << "\n***START OF TEST #3" << endl;
    //Create a dummy commandline arguments
    int argc = 9;
    char *argv[9];
    argv[0] = (char *) malloc(30);
    strcpy(argv[0], "cmd");

    argv[1] = (char *) malloc(30);
    strcpy(argv[1], "-test_int");

    argv[2] = (char *) malloc(30);
    strcpy(argv[2], "40");

    argv[3] = (char *) malloc(30);
    strcpy(argv[3], "-test_float");

    argv[4] = (char *) malloc(30);
    strcpy(argv[4], "1.123456f");

    argv[5] = (char *) malloc(30);
    strcpy(argv[5], "-test_double");

    argv[6] = (char *) malloc(30);
    strcpy(argv[6], "3.333333333333333333");

    argv[7] = (char *) malloc(30);
    strcpy(argv[7], "-test_string");

    argv[8] = (char *) malloc(30);
    strcpy(argv[8], "test");


    ArgumentParser *ap = new ArgumentParser();
    ap->read(argc, argv);

    int a = ap->getInt("test_int");
    float b = ap->getFloat("test_float");
    double c = ap->getDouble("test_double");
    string d = ap->getString("test_string");

    REQUIRE(a == 40);
    REQUIRE(b == 1.123456f);
    REQUIRE(c == 3.333333333333333333);
    REQUIRE(d == "test");

    ap->test_showAll();
    cout << "***END OF TEST #3" << endl;
}

TEST_CASE("TEST #4: HOW ABOUT WRONG CONVERTIBLES?") {
    cout << "\n***START OF TEST #4" << endl;
    //Create a dummy commandline arguments
    int argc = 3;
    char *argv[3];
    argv[0] = (char *) malloc(30);
    strcpy(argv[0], "cmd");

    argv[1] = (char *) malloc(30);
    strcpy(argv[1], "-i");

    argv[2] = (char *) malloc(30);
    strcpy(argv[2], "TEST");


    ArgumentParser *ap = new ArgumentParser();
    ap->read(argc, argv);
    ap->test_showAll();

    int a = ap->getDouble("i");

    REQUIRE(a == 0);
    cout << "***END OF TEST #4" << endl;
}

TEST_CASE("TEST #5: HOW ABOUT BOOLEAN?") {
    cout << "\n***START OF TEST #5" << endl;
    //Create a dummy commandline arguments
    int argc = 2;
    char *argv[2];
    argv[0] = (char *) malloc(30);
    strcpy(argv[0], "cmd");

    argv[1] = (char *) malloc(30);
    strcpy(argv[1], "-test_bool");


    ArgumentParser *ap = new ArgumentParser();
    ap->read(argc, argv);
    ap->test_showAll();

    bool a = ap->getBool("test_bool");

    REQUIRE(a == true);
    cout << "***END OF TEST #5" << endl;
}

TEST_CASE("TEST #6: HOW ABOUT FALSE BOOLEAN?") {
    cout << "\n***START OF TEST #6" << endl;
    //Create a dummy commandline arguments
    int argc = 3;
    char *argv[3];
    argv[0] = (char *) malloc(30);
    strcpy(argv[0], "cmd");

    argv[1] = (char *) malloc(30);
    strcpy(argv[1], "-test_bool");

    argv[2] = (char *) malloc(30);
    strcpy(argv[2], "0");


    ArgumentParser *ap = new ArgumentParser();
    ap->read(argc, argv);
    ap->test_showAll();

    bool a = ap->getBool("test_bool");

    REQUIRE(a == false);
    cout << "***END OF TEST #6" << endl;
}

