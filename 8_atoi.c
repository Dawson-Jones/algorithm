#include<stdio.h>

int mypow(int num, int times){
    int res = 1;
    for(int i=0;i<times;i++)
        res *=num;
    return res;
}

int myAtoi(char * str){
    int min = mypow(-2,31);
    int max = ~min;

    int flag = 1;
    while(*str==' ') str++;
    if (*str!='-'&&*str!='+'&&(*str<'0'||*str>'9')) return 0;
    if(*str=='-'){
        str++;
        flag = 0;
    }else if(*str == '+')
        str++;
    
    long res = 0;
    while(*str>='0'&&*str<='9'){
        res = res*10+(*str-'0');
        if((int)res!=res)
            return flag==1?max:min;
        str++;
    }
    return flag==1?res:(~res+1);
}

int main(){
    while(1){
        char str[1000];
        scanf("%s", str);
        int res = myAtoi(str);
        printf("you number is: %d\n", res);
    }
}
