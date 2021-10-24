#include "tpool.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
 
void* fun(void* args)
{
   int thread = (int)args;
   printf("running the thread of %d\n",thread);
return NULL;
}
 
int main(int argc, char* args[])
{
   tpool_t* pool = NULL;
   if(0 != create_tpool(&pool,5)){
        printf("create_tpool failed!\n");
        return -1;
   }
 
   for(int i = 0; i <= 1000; i++){
        add_task_2_tpool(pool,fun,(void*)i);
   }
   //sleep(2);
   destroy_tpool(pool);
   return 0;
}