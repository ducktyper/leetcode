/**
 * SOURCE: https://leetcode.com/problems/longest-palindromic-substring
 */
char* longestPalindrome(char* s) {
    int mf = 0, ml = 0, i = 0, f = 0, t = 0;
    while(s[i])
    {
        f = i;
        while(s[f] == s[i + 1]) i++;
        t = i;
        while(f > 0 && s[f - 1] == s[t + 1]) {f--; t++; }
        if (ml < t - f + 1)
        {
            mf = f;
            ml = t - f + 1;
        }
        i++;
    }
    char * out = malloc(sizeof(char) * (ml + 1));
    for (int j = 0; j < ml; j++) out[j] = s[mf + j];
    out[ml] = '\0';
    return out;
}
