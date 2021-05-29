#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include <assert.h>
#include <stdlib.h>
//#include <sys/wait.h>
//#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>


int main(void){
   siginfo_t info;
   int pid = vfork();
   if(pid){
       printf("Parent start work\n");
       struct rusage * rus;
       int k = 0;
       while (k<100000000){
          k++;
       }
       printf("Parent waitid start\n");
       waitid(P_PID,pid,&info,WEXITED);
       printf("Parent waitid end\n");
       printf("Result: ==================\n");
       printf("si_signo: %d\n",info.si_signo);
       printf("si_code: %d\n",info.si_code);
       printf("si_pid: %d\n",info.si_pid);
       printf("si_status: %d\n\n",info.si_status);
       printf("Parent end\n");
   }else{
      printf("Son start work\n");
     
      execl("/bin/testpoll2", "/bin/testpoll2", NULL);
      
      
      //exit(0);
      //execl("/bin/testrandom", "/bin/testrandom", NULL);
      //int i=0;
      //printf("I am back!!!\n");
      //fflush(stdout);
      //while(1){
     //   i++;
     // }
   }
   return 0;
}
