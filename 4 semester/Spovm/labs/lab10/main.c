#include "libfiletemp.h"

int main(){


    pthread_t pid;
    pthread_create(&pid, NULL, write_file_aio1, NULL);
    
    init();

    read_file_aio1();
    pthread_join(pid, NULL);
    
    return 0;
}

