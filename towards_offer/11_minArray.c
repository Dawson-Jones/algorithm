// same as leetcode 154
int minArray(int *numbers, int numbersSize) {
    int i = 0, j = numbersSize - 1;
    int m;
    while (i < j) {
        m = i + (j - i) / 2;
        if (numbers[m] > numbers[j])
            i = m + 1;
        else if (numbers[m] < numbers[j])
            j = m;
        else {  // 相等
            j--;
        }
    }
    return numbers[i];
}