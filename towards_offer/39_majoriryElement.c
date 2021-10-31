int majorityElement(int* nums, int numsSize){
    int key = nums[0];
    int power = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == key)
            power++;
        else
            power--;
        
        if(power<=0)
            key = nums[i+1];
    }
    return key;
}