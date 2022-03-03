#include "Function.hpp"

char child_path[] = "/Users/admin/Documents/BSUIR/4 semester/spovm/lab3/lab3/child/a.out";
int main(int argc, const char * argv[], char *envp[]) {
    //printEnvp(envp);
    
    
//    char *childProcess;
//    childProcess = getenv(child_path);
    
    pid_t pid = fork();
    if (pid > 0) {
          // Parent process
          int status;
          wait(&status);
        } else if (pid == 0) {
            if (execve(child_path, NULL, NULL) != 0) {
                std::cout << "don't work" << std::endl;
            }
            
            else {
                std::cout << "yyee" << std::endl;
            }
        }
    
  
}
