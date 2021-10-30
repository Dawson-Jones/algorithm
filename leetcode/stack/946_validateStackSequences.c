bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize) {
    if (pushedSize != poppedSize)
        return false;
    if (pushedSize == 0)
        return true;
        
    int stk[pushedSize];
    int top_idx = 0;
    int pop_idx = 0;

    for (int i = 0; i < pushedSize; ++i) {
        stk[top_idx++] = pushed[i];
        while (top_idx > 0 && stk[top_idx - 1] == popped[pop_idx]) {
            top_idx--;
            pop_idx++;
        }
    }

    return top_idx == 0;
}