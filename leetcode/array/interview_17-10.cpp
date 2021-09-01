#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。

输入：[1,2,5,9,5,9,5,5,5]
输出：5


输入：[3,2]
输出：-1

输入：[2,2,1,1,1,2,2]
输出：2
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res;
        int counts = 0;
        for (auto num : nums) {
            if (!counts) {
                res = num;
                counts++;
            } else {
                res == num ? counts++ : counts--;
            }
        }

        if (counts) {
            counts = 0;
            for (auto num: nums)
                res == num ? counts++ : counts--;

            return counts > 0 ? res : -1;
        } else {
            return -1;
        }
    }
};