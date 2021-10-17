#include "stdio.h"
#include "pthread.h"
#include "unistd.h"

int a = 0;

void *func_thread(void *p) {
  printf("start %d\n", *(int*)p);

  int i=0;
  for(i=0; i < 45; i++){
	int next = a + 1;
	int now = a;
	a = next;
	printf("thread :%d\n", i);
	sleep(1);
	if (now+1 != next) {
	  printf("other theard change %d %d\n", a+1, next);
	}
  }

  return 0;
}

int main(void) {
  sleep(3);
  printf("test\n");

  int b = 42;

  pthread_t pthread;
  pthread_create( &pthread, NULL, &func_thread, &b);
  //pthread_join(pthread, NULL); // pthreadで作られたスレッドが終わるまで待つ

  int i=0;
  for(i=0; i < 10; i++){
	int next = a + 1;
	int now = a;
	a = next;
	printf("main_thread:%d\n", i);
	sleep(1);
	if (now+1 != next) {
	  printf("other theard change %d %d\n", a+1, next);
	}
  }

  pthread_join(pthread, NULL); // pthreadで作られたスレッドが終わるまで待つ
  printf("end a=%d\n", a);

  return 0;
}
