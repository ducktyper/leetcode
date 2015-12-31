/*
 * SOURCE: https://leetcode.com/problems/3sum-closest
 * TIME COMPLEXITY: O(n^2)
 */

void swap(int *array, int i, int j);
void quickSort(int * array, int from, int to);
int  diffClosest(int * array, int from, int to, int value);

int threeSumClosest(int* nums, int numsSize, int target) {
    int ns[numsSize];
    memcpy(ns, nums, sizeof(int) * numsSize);
    quickSort(ns, 0, numsSize - 1);
    int diff = ns[0] + ns[1] + ns[2] - target;
    for (int i = 0; i < numsSize - 2; i++)
    {
        int j = i + 1, k = numsSize - 1;
        while (j < k)
        {
            int d = ns[i] + ns[j] + ns[k] - target;
            if (d == 0) return target;
            if (abs(d) < abs(diff)) diff = d;
            d > 0 ? k-- : j++;
        }
    }
    return target + diff;
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

int diffClosest(int * array, int from, int to, int value)
{
    if (from == to) return array[from] - value;
    if (from + 1 == to)
    {
        return (abs(array[from] - value) < abs(array[to] - value)) ? array[from] - value : array[to] - value;
    }
    int half = (to + from) / 2;
    if (array[half] < value)
        return diffClosest(array, half, to, value);
    else
        return diffClosest(array, from, half, value);
}
