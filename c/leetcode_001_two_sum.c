#include <stdlib.h>

/**
 * SOURCE: https://leetcode.com/problems/two-sum
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int hash = 10000, bucket = 10;
    int* records  = (int *) calloc(hash * bucket, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        int need = target - nums[i];
        int * sub = &records[abs(need % hash) * bucket];
        for (int j = 0; j < bucket; j++)
        {
            if (!sub[j]) break;
            if (nums[sub[j] - 1] == need)
            {
                int* out = (int *) calloc(2, sizeof(int));
                out[0] = sub[j];
                out[1] = i + 1;
                return out;
            }
        }
        sub = &records[abs(nums[i] % hash) * bucket];
        for (int j = 0; j < bucket; j++)
        {
            if (!sub[i] || nums[sub[i] - 1] == nums[i])
            {
                sub[j] = i + 1;
                break;
            }
        }
    }
    return NULL;
}
