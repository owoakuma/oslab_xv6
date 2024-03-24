#include "kernel/types.h"
#include "user.h"

int main(int argc,char* argv[]){
    if(argc != 2){
        printf("Sleep need one arguement!");
        exit(-1);
    }
    int ticks = atoi(argv[1]);
    sleep(ticks);
    printf("(nothing happened for a little while)\n");
    exit(0);
};