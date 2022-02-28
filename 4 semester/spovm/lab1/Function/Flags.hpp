#ifndef Flags_hpp
#define Flags_hpp

#include <iostream>
#include <dirent.h>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <vector>

#define COLOR_RED "\033[1;31;40m"
#define CLEAR_CLS "\033[1;0m"

using namespace std;

struct Flags {
    bool l = false,
         d = false,
         f = false,
         s = false;

public:
    void print_flags() const;
};


#endif /* Flags_hpp */
