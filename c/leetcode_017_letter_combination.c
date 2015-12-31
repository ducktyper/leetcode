/**
 * SOURCE: https://leetcode.com/problems/letter-combinations-of-a-phone-number
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int  nOfLetters(char digit);
char initLetter(char digit);

char** letterCombinations(char* digits, int* returnSize) {
    int length = strlen(digits);
    *returnSize = length ? 1 : 0;
    for (int i = 0; i < length; i++)
    {
        (*returnSize) *= nOfLetters(digits[i]);
    }
    char ** out = malloc(sizeof(char **) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++)
    {
        out[i] = malloc(sizeof(char) * length + 1);
        out[i][length] = '\0';
    }

    int period = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        char init = initLetter(digits[i]);
        int  size = nOfLetters(digits[i]);
        for (int j = 0; j < (*returnSize); j++)
        {
            out[j][i] = init + j / period % size;
        }
        period *= size;
    }

    return out;
}

int nOfLetters(char digit)
{
    return (digit == '7' || digit == '9') ? 4 : 3;
}

char initLetter(char digit)
{
    return 'a' + (digit - '0' - 2) * 3 + (digit == '8' || digit == '9');
}

