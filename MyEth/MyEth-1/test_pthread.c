#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//スレッド本体関数
void *func_null_1(void *arg){
    char test[1024];
    printf("new thread created : %ld \n", pthread_self());
    sleep(5);
    printf("thread exit\n");
    return(0);
}

void *func_null_2(void *arg){
    char test[2048];
    printf("new thread created : %ld \n", pthread_self());
    sleep(5);
    printf("thread exit\n");
    return(0);
}

void *func_null_3(void *arg){
    char test[3072];
    printf("new thread created : %ld \n", pthread_self());
    sleep(5);
    printf("thread exit\n");
    return(0);
}

void *func_null_4(void *arg){
    char test[4096];
    printf("new thread created : %ld \n", pthread_self());
    sleep(5);
    printf("thread exit\n");
    return(0);
}

void *func_null_5(void *arg){
    char test[1024*1024*7];
    printf("new thread created : %ld \n", pthread_self());
    for(int num=0; num<sizeof(test); num++){
        test[num] = 'a';
    }
	//printf("test:%s\n", test);
    sleep(5);
    printf("thread exit\n");
    return(0);
}

void *func_null_6(void *arg){
    char test[204800];
    printf("new thread created : %ld \n", pthread_self());
    sleep(5);
    printf("thread exit\n");
    return(0);
}

void *func_null_7(void *arg){
    char test[303600];
    printf("new thread created : %ld \n", pthread_self());
    sleep(5);
    printf("thread exit\n");
    return(0);
}

void *func_null_8(void *arg){
    char test[404800];
    printf("new thread created : %ld \n", pthread_self());
    sleep(5);
    printf("thread exit\n");
    return(0);
}

int main()
{
    pthread_t th_cli1;
    pthread_t th_cli2;
    pthread_t th_cli3;
    pthread_t th_cli4;
    pthread_t th_cli5;
    pthread_t th_cli6;
    pthread_t th_cli7;
    pthread_t th_cli8;

    pthread_attr_t th_cli_attr;
    int status;


    //--------------------------------------------------------------------------------//
    // スレッド属性を作ってスレッド作成の準備
    //--------------------------------------------------------------------------------//
    pthread_attr_init(&th_cli_attr);
    //pthread_attr_setstacksize(&th_cli_attr, 204800);
    sleep(15);
    //--------------------------------------------------------------------------------//
    // TEST1 スレッドを6個作成
    //--------------------------------------------------------------------------------//
    status = pthread_create(&th_cli1,&th_cli_attr,func_null_1,NULL);
    status = pthread_create(&th_cli2,&th_cli_attr,func_null_2,NULL);
    status = pthread_create(&th_cli3,&th_cli_attr,func_null_3,NULL);
    status = pthread_create(&th_cli4,&th_cli_attr,func_null_4,NULL);
    status = pthread_create(&th_cli5,&th_cli_attr,func_null_5,NULL);
    status = pthread_create(&th_cli6,&th_cli_attr,func_null_6,NULL);

    sleep(15);
    pthread_join(th_cli1,NULL);
    pthread_join(th_cli2,NULL);
    pthread_join(th_cli3,NULL);
    pthread_join(th_cli4,NULL);
    pthread_join(th_cli5,NULL);
    pthread_join(th_cli6,NULL);

    sleep(5);
    printf("6 thread finished\n");
    sleep(15);
    //--------------------------------------------------------------------------------//
    // TEST2 スレッドを2個作成
    //--------------------------------------------------------------------------------//
    status = pthread_create(&th_cli7,&th_cli_attr,func_null_7,NULL);
    status = pthread_create(&th_cli8,&th_cli_attr,func_null_8,NULL);

    pthread_join(th_cli7,NULL);
    pthread_join(th_cli8,NULL);
    
    sleep(10);
    printf("th_cli1 : %ld\n", th_cli1);
    printf("th_cli2 : %ld\n", th_cli2);
    printf("th_cli3 : %ld\n", th_cli3);
    printf("th_cli4 : %ld\n", th_cli4);
    printf("th_cli5 : %ld\n", th_cli5);
    printf("th_cli6 : %ld\n", th_cli6);
    printf("th_cli7 : %ld\n", th_cli7);
    printf("th_cli8 : %ld\n", th_cli8);
    printf("exit\n");
    sleep(10);
    return(0);
}
