bool verifyPostorder(int* postorder, int postorderSize){
    if (postorderSize <= 1)
        return true;
    
    int root = postorder[postorderSize-1];
    
    // left;
    int i, j;
    for (i = 0; postorder[i] < root; ++i);
    
    // right;
    for (int j = i; j < postorderSize-1; ++j) {
        if (postorder[j] < root)
            return false;
    }
    
    return verifyPostorder(postorder, i) && verifyPostorder(postorder + i, postorderSize - i - 1);
}
