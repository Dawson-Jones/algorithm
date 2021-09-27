int getSum(int a, int b){
    return b ? getSum(a ^ b, (unsigned int) (a & b) << 1) : a;
}