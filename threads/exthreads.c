#include <stdio.h>
#include <pthread.h>
#define SIZE 10

int v[SIZE];
void *function(void *arg){
    int i;
    int *value = (int*)arg;

    if(*value == 1){
        printf("Thread 1 executando ...\n");
        for(i = 0; i < SIZE/2; i++)
        {
            v[i] = 1;
        }
    }
    else{
        printf("Thread 2 executando...\n");
        for( i = SIZE/2; i < SIZE; i++)
        {
            v[i] = 2;
        }
    }
}

int main(){
    pthread_t t1, t2;
    int arg1 = 1;
    int arg2 = 2;
 
    pthread_create(&t1, NULL, function, (void*)&arg1);
    pthread_create(&t2, NULL, function, (void*)&arg2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", v[i]);
    }
    
    return 0;
}