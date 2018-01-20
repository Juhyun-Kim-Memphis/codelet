//#include <stdio.h>
//#include <gtest/gtest.h>
//#include "switch.hpp"
//
//// Default option shall be one higher than the last
//enum { ADD = 0, SUB = 1, MUL = 2, DIV = 3, MOD = 4, DEFAULT = 5 };
//
//template <int Operation>
//struct interpreter {
//    static inline int run(const int x, const int y);
//};
//
//// Our default operation: XOR
//template <>
//struct interpreter<DEFAULT> {
//    static const char *name() { return "XOR"; }
//    static inline int run(const int x, const int y) {
//        return x^y;
//    }
//};
//
//template <> struct interpreter<ADD> {
//    static const char *name() { return "ADD"; }
//    static inline int run(const int x, const int y)
//    { return x + y; }
//};
//
//template <> struct interpreter<SUB> {
//    static const char *name() { return "SUB"; }
//    static inline int run(const int x, const int y)
//    { return x - y; }
//};
//
//template <> struct interpreter<MUL> {
//    static const char *name() { return "MUL"; }
//    static inline int run(const int x, const int y)
//    { return x * y; }
//};
//
//template <> struct interpreter<DIV> {
//    static const char *name() { return "DIV"; }
//    static inline int run(const int x, const int y)
//    { return x / y; }
//};
//
//template <> struct interpreter<MOD> {
//    static const char *name() { return "MOD"; }
//    static inline int run(const int x, const int y)
//    { return x % y; }
//};
//
//template <int Operation>
//struct operation_table {
//    static always_inline int value(const bool printResult,
//                                   const int x, const int y) {
//        const int r = interpreter<Operation>::run(x, y);
//        if (printResult) printf("operation_table<%s>::run(%i, %i) = %i\n",
//                                interpreter<Operation>::name(), x, y, r);
//        return r;
//    }
//};
//
//
//TEST(TemplateMetaProgramming, testSwitch) {
//    bool printResult = true;
//    int op,x,y;
//
//    printf("op,x,y: ");
//    scanf("%i,%i,%i", &op, &x, &y);
//
//    metalevel::switch_table<0,4, operation_table>::run<int>(op,printResult,x,y);
//
//    // no default:
//    metalevel::switch_table<0,4, operation_table, false>::run<int>(op,printResult,x,y);
//}
