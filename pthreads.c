#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

#define NUM_THREADS 10
int thread_idx = 0;
int sum = 0;               /* this data is shared by the thread(s) */
void *runner1(void *param); /* threads call this function */
void *runner2(void *param);
int main(int argc, char *argv[])
{
  pthread_t workers[NUM_THREADS];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  for (int pt = 0; pt < NUM_THREADS; pt++){
      pthread_create(&workers[pt], &attr, runner1, argv[1]);
      // sleep(2);

  }
  for (int pt = 0; pt < NUM_THREADS; pt++){
      pthread_join(workers[pt], NULL);

  }
  printf("Main thread : %d", sum);
}

void *runner1(void *param){
  for (int i = 0; i < 5000; i++)
  {
    sum++;
  }
  printf("Thread %d : %d \n", pthread_self(), sum);
  pthread_exit(0);   
}

void *runner2(void *param){
    printf("child thread \n");
}