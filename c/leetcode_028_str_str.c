/*
 * SOURCE: https://leetcode.com/problems/implement-strstr
 */
int strStr(char* haystack, char* needle) {
    if (!*needle) return 0;

    int out = 0, backup = 0, i = 0, second_char_at = 0;

    while (needle[++second_char_at] == needle[0]) { }

    do
    {
        if (!out)
        {
            if (haystack[i] == needle[0]) out = i + 1;
        }
        else
        {
            int j = i - out + 1;

            if (!needle[j]) return out - 1;

            if (haystack[i] == needle[0])
            {
                if (j == second_char_at) { out++; backup = 0; continue; }
                if (!backup) backup = i + 1;
            }
            if (haystack[i] != needle[j])
            {
                out = backup;
                if (backup) { i = backup - 1; backup = 0; }
            }
        }
    } while (haystack[i++]);

    return -1;
}
