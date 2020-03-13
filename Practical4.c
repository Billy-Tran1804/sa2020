#include <unistd.h>
#include <stdio.h>
#include <string.h>

int pid;
void handler (int signal_num) {
    printf("Signal %d => ", signal_num);
    if (signal_num == SIGTSTP) {
        signal(SIGTSTP, handler);
        return 0;
    }
}
int main () {
     while(1) {
    char str[100];
    printf("Please input value: ");
    scanf("%s",str);
        
    if (strcmp(str,"quit") == 0) {
        return 0;
    }
    printf("Main before fork() \n");
    pid = fork();
    if (pid == 0) 
    {
        printf("I am child after fork() \n");        
        char *argv[3];
        argv[0] = "ls";
        argv[1] = "-la";
        argv[2] = NULL;
        execvp(str, argv);
        
    }    
    else 
    
    {
        printf("I am parent after fork(), child is %d\n", pid);
        wait(NULL);
    }
  }
}