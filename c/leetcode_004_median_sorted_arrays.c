/**
 * SOURCE: https://leetcode.com/problems/median-of-two-sorted-arrays
 */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int s1 = 0, s2 = 0, e1 = nums1Size - 1, e2 = nums2Size - 1;
    while (s1 <= e1 || s2 <= e2)
    {
        int i1 = e1 - s1, i2 = e2 - s2;
        double m1 = s1 > e1 ? 0 : nums1[s1 + i1 / 2] + nums1[s1 + (i1 + 1) / 2];
        double m2 = s2 > e2 ? 0 : nums2[s2 + i2 / 2] + nums2[s2 + (i2 + 1) / 2];

        if (s1 > e1)              return m2 / 2.0;
        if (s2 > e2)              return m1 / 2.0;
        if (m1 == m2)             return m1 / 2.0;
        if (s1 == e1 && s2 == e2) return (m1 + m2) / 4.0;

        int cut = (i1 < i2 ? i1 : i2) / 2;
        if (m1 < m2)
        {
            s1 += cut; e2 -= cut;
        }
        else
        {
            s2 += cut; e1 -= cut;
        }

        nums1[s1] < nums2[s2] ? s1++ : s2++;
        nums1[e1] > nums2[e2] ? e1-- : e2--;
    }
    return 0;
}
