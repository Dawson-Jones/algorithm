bool isStraight(int* nums, int numsSize){
    int set[14];
    int m_min = INT32_MAX, m_max = INT32_MIN;
    memset(set, 0, sizeof(set));
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0)
            continue;
        
        if (set[nums[i]]++)
            return false;
        
        m_min = m_min < nums[i] ? m_min : nums[i];
        m_max = m_max > nums[i] ? m_max : nums[i];
    }
    return m_max - m_min < 5;
}