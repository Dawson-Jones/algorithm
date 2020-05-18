#include <stdio.h>

int fib(int n){
    int first = 0;
    int second = 1;
    int res;
    if (n<2)
        return n;
    for (int i = 0; i < n-1; i++){
        res = (first + second);
        first = second;
        second = res;
    }
    return res;
}

int main(int argc, char const *argv[]){
    int count = fib(45);
    printf("%d\n", count);
    return 0;
}
