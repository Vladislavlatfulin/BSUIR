#ifndef helper_h
#define helper_h

void printEnvpParent(char* envp[]);
char** createEnvpChild(char* fenvp);

char* findChildPath(char** str_arr);

#endif 
