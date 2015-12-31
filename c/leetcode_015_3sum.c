/**
 * SOURCE: https://leetcode.com/problems/3sum
 * TIME COMPLEXITY: O(n^2)
 *
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *array, int i, int j);
void quickSort(int * array, int from, int to);

int** threeSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;

    int ns[numsSize];
    memcpy(ns, nums, sizeof(int) * numsSize);
    quickSort(ns, 0, numsSize - 1);

    int * matches[numsSize];
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && ns[i] == ns[i - 1]) continue;
        if (ns[i] > 0) break;

        int j = i + 1, k = numsSize - 1;
        while (j < k)
        {
            int jv = ns[j], kv = ns[k], sum = ns[i] + jv + kv;
            if (sum == 0)
            {
                int * m = malloc(sizeof(int) * 3);
                m[0] = ns[i];
                m[1] = jv;
                m[2] = kv;
                matches[(*returnSize)++] = m;
            }
            if (sum > 0) do { k--; } while (kv == ns[k]);
            else         do { j++; } while (jv == ns[j]);
        }
    }

    int ** out = (int **) malloc(sizeof(int *) * (*returnSize));
    memcpy(out, matches, sizeof(int **) * (*returnSize));

    return out;
}

void swap(int *array, int i, int j)
{
  int c = array[i]; array[i] = array[j]; array[j] = c;
}

void quickSort(int * array, int from, int to)
{
    if (from > to) return;
    int pivot = array[to], p = from;
    for (int i = from; i < to; i++)
    {
        if (array[i] <= pivot) swap(array, i, p++);
    }
    swap(array, to, p);
    quickSort(array, from, p - 1);
    quickSort(array, p + 1, to);
}
