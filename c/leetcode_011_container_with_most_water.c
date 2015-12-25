/*
 * SOURCE: https://leetcode.com/problems/container-with-most-water
 */
int maxArea(int* height, int heightSize) {
    int max = 0, i = 0, j = heightSize - 1;
    while (i < j)
    {
        int area = (j - i) * (height[i] > height[j] ? height[j--] : height[i++]);
        if (max < area) max = area;
    }
    return max;
}
