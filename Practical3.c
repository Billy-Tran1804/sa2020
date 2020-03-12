#include <unistd.h>
#include <stdio.h>
int main() {
    while(1) {
    char str[100];
    scanf("%[^\n]s",str);
    printf("%s",str);
    if (str == "quit") {
        break;
    }
    printf("Main before fork() \n");
    int pid = fork();
    if (pid == 0) 
    {
        printf("I am child after fork() \n");
        char *args[] = {"run", "stop", "pause"};
        execvp("run", args);
    }    
    else printf("I am parent after fork(), child is %d\n", pid);
    Wait(NULL);
    return 0;
    }
}
