//
// Created by juhyun on 17. 10. 13.
//

#ifndef NETWORK_UTIL_HPP
#define NETWORK_UTIL_HPP

#include <string>

using namespace std;

string getCmdOption(int argc, char* argv[], const string& option)
{
    string cmd;
     for( int i = 0; i < argc; ++i)
     {
          string arg = argv[i];
          if(0 == arg.find(option))
          {
               size_t found = arg.find_last_of(option);
               cmd =arg.substr(found + 1);
               return cmd;
          }
     }
     return cmd;
}

#endif //NETWORK_UTIL_HPP
