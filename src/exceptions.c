void divisionByZeroExceptionHandle(int signal){
    ;
}

#include <signal.h>
#include <stdio.h>

int main(){
    void (*sigHandle)(int);
    sigHandle = signal(SIG_ERR,divisionByZeroExceptionHandle);

    if (sigHandle == SIG_ERR){
        perror("Zero error");
        return 1;
    }
    int num1 = 0, num2 = 1;
    int result = num2 / num1;
    printf("Result: %d\n", result);
    return 0;
}