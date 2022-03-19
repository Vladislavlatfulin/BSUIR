#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>

const char COLOR_ON[] = "\033[1;32m";
const char COLOR_OFF[] = "\033[0m";

int main(int argc, char* argv[], char* envp[]) {
  if (argc != 2) {
    fprintf(stderr, "%d is invalid arguments amount, must be 2\n", argc);
    exit(EXIT_FAILURE);
  }

  printf(COLOR_ON); // Green color

  puts("Child process data:");
  printf("Name: %s\n", argv[0]);
  printf("Pid: %d\n", getpid());
  printf("Ppid: %d\n", getppid());

  int size = 256;
  char tempString[size];
  FILE* fenvp = fopen(argv[1], "r");
  if (!fenvp) {
    perror("fenvp");
    exit(errno);
  }
  while (fgets(tempString, size, fenvp) != NULL) {
    tempString[strcspn(tempString, "\n")] = '\0';
    printf("%s=%s\n", tempString, getenv(tempString));
  }

  printf(COLOR_OFF); 

  fclose(fenvp);
  exit(EXIT_SUCCESS);
}
