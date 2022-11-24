#include "tpool.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
 
void* fun(void* args)
{
   int* thread = (int*)args;
   printf("running the thread of %d\n",*thread);
   free(thread);
   return NULL;
}
 
int main()
{
   tpool_t* pool = NULL;
   if(0 != create_tpool(&pool,5)){
        printf("create_tpool failed!\n");
        return -1;
   }
 
   for(int i = 0; i < 5000; i++){
      int* a=(int*)malloc(sizeof(int));
      *a=i;
      add_task_2_tpool(pool,fun,a);
   }
   //sleep(2);
   destroy_tpool(pool);
   return 0;
}
