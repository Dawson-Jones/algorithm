#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        bool is_odd = nums1.size() % 2;
        int mid = nums1.size() / 2;
        if (is_odd) {
            return nums1[mid];
        } else {
            return double (nums1[mid-1] + nums1[mid]) / 2;
        }
    }
};