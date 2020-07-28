/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start

int find(int*nums, int numsSize, int count, int a)
{   
    int i = count + 1;
    for(i; i < numsSize; i++)
    {
        if(nums[i] == a)
            return i;
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0;
    *returnSize = 0;
    int* buf = (int*)calloc(2, sizeof(int));
    for(i; i < numsSize; i++)
    {
        int tmp = find(nums, numsSize, i, target-nums[i]);
        if( tmp!= -1) 
        {
            buf[0] = i;
            buf[1] = tmp;
            *returnSize = 2;
            break;
        }
    }
    return buf;
}


// @lc code=end

