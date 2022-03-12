#ifndef Flags_hpp
#define Flags_hpp

#include <iostream>
#include <dirent.h>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Flags {
    bool l = false,
         d = false,
         f = false,
         s = false;

public:
    void printFlags() const;
};


#endif /* Flags_hpp */
