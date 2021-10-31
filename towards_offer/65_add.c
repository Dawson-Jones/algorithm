// 位运算
int add(int a, int b){
    unsigned int c;
    while (b) {
        c = (unsigned int)(a & b) << 1;
        a ^= b;
        b = c;
    }
    return a;
}
