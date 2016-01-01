/**
 * SOURCE: https://leetcode.com/problems/4sum
 *
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *array, int i, int j);
void quickSort(int * array, int from, int to);

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;

    int ns[numsSize];
    memcpy(ns, nums, sizeof(int) * numsSize);
    quickSort(ns, 0, numsSize - 1);

    int * matches[numsSize * 2];
    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && ns[i] == ns[i - 1]) continue;

        for (int l = i + 1; l < numsSize - 2; l++)
        {
            if (l > i + 1 && ns[l] == ns[l - 1]) continue;
            int j = l + 1, k = numsSize - 1;

            if (ns[i] + ns[l] + ns[k - 1] + ns[k] < target ||
                ns[i] + ns[l] + ns[j] + ns[j + 1] > target) continue;

            while (j < k)
            {
                int jv = ns[j], kv = ns[k], sum = ns[i] + ns[l] + jv + kv;
                if (sum == target)
                {
                    int * m = malloc(sizeof(int) * 4);
                    m[0] = ns[i];
                    m[1] = ns[l];
                    m[2] = jv;
                    m[3] = kv;
                    matches[(*returnSize)++] = m;
                }
                if (sum > target) do { k--; } while (kv == ns[k]);
                else              do { j++; } while (jv == ns[j]);
            }
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
