#include<stdio.h>

int getNext(int n){
    int sum = 0;
    while(n){
        sum +=(n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

int isHappy(int n){
    int next1 = getNext(n);
    int next2 = getNext(getNext(n));
    while(next1!=next2){
        next1 = getNext(next1);
        next2 = getNext(getNext(next2));
    }
    return (next1==1)?1:0;
}

int main(){
    int i = 19;
    int res = isHappy(i);
    printf("The res: %d is %d happy num", i, res);
}
