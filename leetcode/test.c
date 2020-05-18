#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

int *mall_test(){
    int *res = (int *)malloc(4 * sizeof(int));
    if(res == NULL) exit(1);
    int count = 0;
    while(count<4){
        *res++ = count++;
    }

    return res-4;
}

int main(int argc, char const *argv[])
{
    int *res = mall_test();
    for(int i=0;i<4;i++)
        printf("%d\n", res[i]);

    free(res);
    return 0;
}
