/**
 * SOURCE: https://leetcode.com/problems/longest-substring-without-repeating-characters
 */
int lengthOfLongestSubstring(char* s) {
    int max = 0, start = 0, i = 0, c = 0, used[256] = { 0 };
    do {
        c = (int)s[i];
        if (max < i - start) max   = i - start;
        if (start < used[c]) start = used[c];
        used[c] = ++i;
    } while (c);
    return max;
}
