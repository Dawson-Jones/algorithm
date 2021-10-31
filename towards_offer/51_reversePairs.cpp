// 归并排序
class Solution {
public:
    int count = 0;

    int reversePairs(vector<int> &nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return count;
    }

private:
    void merge_sort(vector<int> &nums, int st1, int ed2) {
        if (st1 >= ed2)
            return;
        int fixed = st1;
        int ed1 = st1 + (ed2 - st1) / 2;
        int st2 = ed1 + 1;
        merge_sort(nums, st1, ed1);
        merge_sort(nums, st2, ed2);
        vector <int> tmp(ed2 - st1 + 1);
        int idx = 0;
        while (st1 <= ed1 && st2 <= ed2) {
            if (nums[st2] < nums[st1]) {
                count += (ed1 - st1 + 1);
                tmp[idx++] = nums[st2++];
            } else {
                tmp[idx++] = nums[st1++];
            }
        }
        while (st1 <= ed1)
            tmp[idx++] = nums[st1++];
        while (st2 <= ed2)
            tmp[idx++] = nums[st2++];

        for (int i = 0; i < idx; ++i) {
            nums[fixed + i] = tmp[i];
        }
    }
};
