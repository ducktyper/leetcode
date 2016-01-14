/*
 * SOURCE: https://leetcode.com/problems/remove-duplicates-from-sorted-array
 */
int removeDuplicates(int* nums, int numsSize) {
    if (!numsSize) return 0;
    int count = 1;
    for(int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1]) nums[count++] = nums[i];
    }
    return count;
}
