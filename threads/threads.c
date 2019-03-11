#include <stdio.h>
#include <pthread.h>
#define N_THREADS 4

void delay(){
    int i, j, k;
    for(i = 0; i < 1000; i++)
        for(j = 0; j < 1000; j++)
            for(k = 0; k < 1000; k++);
}

void *function(void *arg){
    int *pvalue;
    pvalue = arg;

    printf("Thread %d executando ...\n", *pvalue);
    delay();
    printf("Thread %d finalizada!\n", *pvalue);
}

int main(){
    pthread_t threads[N_THREADS];
    int i, arg[N_THREADS];

   for( i = 0; i < N_THREADS; i++)
   {
       arg[i] = i+1;
       pthread_create(&threads[i], NULL, function, (void*)&arg[i]);
   }

   for( i = 0; i < N_THREADS; i++)
   {
       pthread_join(threads[i], NULL);
   }
   
   printf("\n");
    
    return 0;
}
