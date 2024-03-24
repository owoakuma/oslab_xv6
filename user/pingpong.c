#include "kernel/types.h"
#include "user.h"

int main(int argc, char* argv[]){
    if(argc != 1){
        printf("pingpong need no argument!\n");
        exit(-1);
    }
    int p1[2];
    int p2[2];
    pipe(p1);
    pipe(p2);
    char buf[50];
    if(fork() == 0){
        // 子进程
        close(p1[1]);
        close(p2[0]);
        read(p1[0],buf,50);
        printf("%d: received %s\n",getpid(),buf);
        close(p1[0]);
        strcpy(buf,"pong");
        write(p2[1],buf,50);
        close(p2[1]);
        exit(0);
    }else{
        // 父进程
        close(p1[0]);
        close(p2[1]);
        strcpy(buf,"ping");
        write(p1[1],buf,50);
        close(p1[1]);
        read(p2[0],buf,50);
        close(p2[0]);
        printf("%d: received %s\n",getpid(),buf);
        exit(0);
    }
}