/**
 * SOURCE: https://leetcode.com/problems/generate-parentheses
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;

    int max = 1;
    for (int i = 1; i <= n; i++) max *= i;
    char * solutions[max];

    int level[n];
    for (int i = 0; i < n; i++) level[i] = i;

    int length = n * 2;
    int j = n - 1;
    while (j >= 0)
    {
        char * s = malloc(sizeof(char) * (length + 1));
        int p = 0, l = -1;
        for (int i = 0; i < length; i++)
        {
            if (p >= n || level[p] <= l) { s[i] = ')'; l--; }
            else                         { s[i] = '('; p++; l++; }
        }
        s[length] = '\0';
        solutions[(*returnSize)++] = s;

        if (level[j] > 0) level[j]--;
        else
        {
            while(--j >= 0 && level[j] == 0) {}
            if (j >= 0)
            {
                level[j]--;
                for (int i = 1; i < n - j; i++) level[j + i] = level[j] + i;
                j = n - 1;
            }
        }
    }

    int size = sizeof(char **) * (*returnSize);
    char ** out = malloc(size);
    memcpy(out, solutions, size);

    return out;
}
