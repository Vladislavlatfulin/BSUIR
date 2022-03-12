#include "helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

const char childPath[] = "CHILD_PATH";
const char COLOR_ON[] = "\033[1;35m";
const char COLOR_OFF[] = "\033[0m";

static int qsort_cmp(const void* str1, const void* str2) {
    return strcmp(*(const char**) str1, *(const char**) str2);
}

void printEnvpParent(char* envp[]) {
    size_t envpc = 0;
    while (envp[envpc]) {
        ++envpc;
    }
    
    qsort(envp, envpc, sizeof(char*), qsort_cmp);
    
    printf(COLOR_ON); // Purple color
    
    puts("Parent environment variables: ");
    for (size_t i = 0; i < envpc; ++i) {
        puts(envp[i]);
    }
    
    printf(COLOR_OFF);
}

char** createEnvpChild(char* fenvp) {
    FILE* fileWithEnvp = fopen(fenvp, "r");
    if (!fileWithEnvp) {
        perror("fopen");
        exit(errno);
    }
    
    char** envp = malloc(sizeof(char*));
    size_t i = 0;
    
    int size = 256;
    char tempString[size];
    while (fgets(tempString, size, fileWithEnvp) != NULL) { // считывание с файла
        tempString[strcspn(tempString, "\n")] = '\0'; // возвращает кол-во до "\n"
        
        char* env_val = getenv(tempString); // возращает указатель на инфу (хеш-таблица) назначение параметра
        if (env_val) {
            envp[i] = malloc((strlen(tempString) + strlen(env_val) + 2) * sizeof(char));
            strcat(strcat(strcpy(envp[i], tempString), "="), env_val); // получаем ключ + значение в env
            envp = realloc(envp, (++i + 1) * sizeof(char*));
        }
    }
    envp[i] = NULL;
    
    return envp;
}

char* findChildPath(char** arrayWithChildPath) {
    while (*arrayWithChildPath) {
        if (!strncmp(*arrayWithChildPath, childPath, strlen(childPath))) {
            return *arrayWithChildPath + strlen(childPath) + 1; // skip CHILD_PATH=
        }
        ++arrayWithChildPath;
    }
    return NULL;
}
