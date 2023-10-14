#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10
int thread_idx = 0;
int sum = 0;               /* this data is shared by the thread(s) */
void *runner(void *param); /* threads call this function */
int main(int argc, char *argv[])
{
  pthread_t workers[NUM_THREADS];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  for (int pt = 0; pt < NUM_THREADS; pt++){
      pthread_create(&workers[pt], &attr, runner, argv[1]);

  }
  for (int pt = 0; pt < NUM_THREADS; pt++){
      pthread_join(workers[pt], NULL);

  }
  printf("Main thread : %d", sum);
}

void *runner(void *param){
  thread_idx++;
  for (int i = 0; i < 10; i++)
  {
    sum++;
  }
    printf("Thread %d : %d \n", thread_idx, sum);
}