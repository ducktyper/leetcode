/*
 * SOURCE: https://leetcode.com/problems/longest-common-prefix
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    char * out = malloc(sizeof(char) * 100);
    strcpy(out, strsSize ? strs[0] : "");
    for (int i = 1; i < strsSize; i++)
    {
        int j = 0;
        while(out[j] && strs[i][j] && out[j] == strs[i][j]) j++;
        out[j] = '\0';
    }
    return out;
}
