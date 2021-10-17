#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

//スレッド本体関数
void *func_null_1(void *arg){
    char *threadmem;
    threadmem = (char*)malloc(sizeof(char)*(1024*1024));
    printf("new thread created : %ld \n", pthread_self());
    for(int i=0; i<(1024*1024); i++) threadmem[i]='a';
    printf("threadmem:%d\n", threadmem[0]);
    for(int i=0; i<5; i++){sleep(1); printf("loop_1\n");};   
    printf("thread exit\n");
    free(threadmem);
    //return(0);
}

void *func_null_2(void *arg){
    char *threadmem;
    threadmem = (char*)malloc(sizeof(char)*(2048*2048));
    printf("new thread created : %ld \n", pthread_self());
    for(int i=0; i<(2048*2048); i++) threadmem[i]='a';
    printf("threadmem:%d\n", threadmem[0]);
    for(int i=0; i<5; i++){sleep(1); printf("loop_2\n");};   
    printf("thread exit\n");
    free(threadmem);
    //return(0);
}

int main()
{
    pthread_t th_cli1;
    pthread_t th_cli2;

    pthread_attr_t th_cli_attr;
    int status;
    char* malmem;
    int base;

    //--------------------------------------------------------------------------------//
    // スレッド属性を作ってスレッド作成の準備
    //--------------------------------------------------------------------------------//
    pthread_attr_init(&th_cli_attr);
    pthread_attr_setdetachstate(&th_cli_attr,PTHREAD_CREATE_JOINABLE);
    //pthread_attr_setdetachstate(&th_cli_attr,PTHREAD_CREATE_DETACHED);
    //printf("join_or_detached : %d \n", pthread_attr_getdetachstate(&th_cli_attr, &base));
    //printf("join_or_detached : %d \n", base);
    //printf("attr:%s\n", get);
    //pthread_attr_setstacksize(&th_cli_attr, 204800);
    sleep(15);
    //printf("malloc\n");
    //malmem = (char*)malloc(sizeof(char)*10240000);
    //--------------------------------------------------------------------------------//
    // TEST1 スレッドを6個作成
    //--------------------------------------------------------------------------------//
    status = pthread_create(&th_cli1,&th_cli_attr,func_null_1,NULL);

    //sleep(7);
    //for(int i=0; i<10240000; i++) malmem[i]='a';
    //printf("malmem: %s\n", malmem);
    status = pthread_create(&th_cli2,&th_cli_attr,func_null_2,NULL);
    sleep(7);
    pthread_join(th_cli1,NULL);
    pthread_join(th_cli2,NULL);
    //time_t t1,t2;
    //t1 = time(NULL);
    //printf("%ld\n",t1);
    for(int i=0; i<15; i++){sleep(1); printf("loop\n");};   

    sleep(15);
    //pthread_join(th_cli1,NULL);
    //pthread_join(th_cli2,NULL);

    sleep(5);
    printf("6 thread finished\n");
    sleep(15);
    //--------------------------------------------------------------------------------//
    // TEST2 スレッドを2個作成
    //--------------------------------------------------------------------------------//

    sleep(10);
    printf("free\n");
    //free(malmem);
    printf("th_cli1 : %ld\n", th_cli1);
    printf("th_cli1 : %ld\n", th_cli2);
    printf("exit\n");
    sleep(10);
    return(0);
}
