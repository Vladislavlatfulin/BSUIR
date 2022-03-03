#include "Function.hpp"



static int qsort_cmp(const void* str1, const void* str2) {
  return strcmp(*(const char**) str1, *(const char**) str2);
}

int countEnvp(char *envp[]) {
    int i;
    for (i = 0; envp[i]; i++);
    return i;
}

void printEnvp(char *envp[]) {
    int envpCout = countEnvp(envp);
    
    qsort(envp, envpCout, sizeof(char*), qsort_cmp);
    
    std::cout << "parent envp after sort\n";
    
    for (int i = 0; i < envpCout; i++) {
        std::cout << envp[i] << std::endl;
    }
}

