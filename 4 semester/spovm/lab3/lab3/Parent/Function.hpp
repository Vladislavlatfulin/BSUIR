#ifndef Function_hpp
#define Function_hpp

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>


void printEnvp(char *envp[]);
int countEnvp(char *envp[]);

#endif /* Function_hpp */
