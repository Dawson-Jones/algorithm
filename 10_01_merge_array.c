#include<stdio.h>
void merge(int *A, int ASize, int m, int *B, int BSize, int n)
{
    int pointA = m-1;
    int pointB = n-1;
    int cur = n+m-1;
    while(pointA>-1&&pointB>-1){
       if(A[pointA]>B[pointB]){
           A[cur] = A[pointA];
           pointA--;
           
       }else{
            A[cur] = B[pointB];
            pointB--;
        }
       cur--;
    }
    if(pointB>-1)
        for(int i=0;i<=pointB;i++)
            A[i] = B[i];
        
}

int main(int argc, char const *argv[])
{
    int A[6] = {1, 2, 3, 0, 0, 0};
    int B[3] = {2, 5, 6};
    merge(A, 6, 3, B, 3,3);
    for(int i=0;i<6;i++){
        printf("%d\n", A[i]);
    }
    return 0;
}
