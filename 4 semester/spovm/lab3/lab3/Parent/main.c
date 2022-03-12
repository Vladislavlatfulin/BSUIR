#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/wait.h>
#include <unistd.h>

#include "helper.h"

extern char** environ;
extern const char childPath[];

int main(int argc, char* argv[], char* envp[]) {
    if (argc != 2) {
        fprintf(stderr, "%d is invalid amount of arguments, must be 2\n", argc);
        exit(EXIT_FAILURE);
    }
    
    printEnvpParent(envp);
    char* const* envpChild = createEnvpChild(argv[1]); // env.txt
    
    size_t childСount = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == 'q') {
            exit(EXIT_SUCCESS);
        }
        if (c != '+' && c != '*' && c != '&') {
            continue;
        }
        
        // Get path to child process
        char* childProcessString = NULL;
        switch ((char) c) {
            case '+':
                childProcessString = getenv(childPath);
                break;
                
            case '*':
                childProcessString = findChildPath(envp);
                break;
                
            case '&':
                childProcessString = findChildPath(environ);
                break;
        }
        
        char childName[10];
        sprintf(childName, "child_%zu", childСount++);
        
        char* const argvForChild[] = {childName, argv[1], NULL};  // argv for child
        
        pid_t pid = fork();
        if (pid > 0) {
            int status;
            wait(&status);
        } else if (pid == 0) {
            if (execve(childProcessString, argvForChild, envpChild) == -1) {
                perror("execve");
                exit(errno);
            }
        } else {
            perror("fork");
            exit(errno);
        }
    }
    if (c == EOF) {
        perror("getchar");
        exit(errno);
    }
}
