#include <gtest/gtest.h>
#include "Movie.hpp"
#include "Customer.hpp"
#include "Rental.hpp"


TEST(MovieRental, test) {
    Customer john(string("john"));
    Movie her(string("her"), 0);
    Movie titanic(string("titanic"), 1);
    Movie pororo(string("pororo"), 2);

    john.addRental(Rental(pororo, 5));
    john.addRental(Rental(titanic, 6));
    john.addRental(Rental(her, 1));

    EXPECT_EQ(john.statement(), string(
            "john: your rental history\n"
                    "\tpororo\t4.500000\n"
                    "\ttitanic\t8.000000\n"
                    "\ther\t3.000000\n"
                    "accumulated amount: 15.500000\n"
                    "total point: 3\n"));
}

TEST(MovieRental, testMemphis) {
    Customer memphis(string("memphis"));
    Movie pororo(string("pororo"), 2);
    Movie her(string("her"), 0);

    memphis.addRental(Rental(pororo, 1));
    memphis.addRental(Rental(her, 5));

    EXPECT_EQ(memphis.statement(), string(""
          "memphis: your rental history\n"
          "\tpororo\t1.500000\n"
          "\ther\t15.000000\n"
          "accumulated amount: 16.500000\n"
          "total point: 3\n"
    ));
}

TEST(MovieRental, testGuldan) {
    Customer guldan(string("guldan"));
    Movie her(string("her"), 0);
    Movie her2(string("her2"), 0);
    Movie titanic(string("titanic"), 1);
    Movie titanic2(string("titanic2"), 1);

    guldan.addRental(Rental(her, 3));
    guldan.addRental(Rental(her2, 1));
    guldan.addRental(Rental(titanic, 7));
    guldan.addRental(Rental(titanic2, 2));

    EXPECT_EQ(guldan.statement(), string(""
         "guldan: your rental history\n"
         "\ther\t9.000000\n"
         "\ther2\t3.000000\n"
         "\ttitanic\t9.500000\n"
         "\ttitanic2\t2.000000\n"
         "accumulated amount: 23.500000\n"
         "total point: 5\n"
    ));
}