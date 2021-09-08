struct TreeNode *helper(int *nums, int l, int r) {
    if (l > r) 
        return NULL;
    int mid = (l + r) / 2;
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = helper(nums, l, mid-1);
    root->right = helper(nums, mid+1, r);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return helper(nums, 0, numsSize-1);
}