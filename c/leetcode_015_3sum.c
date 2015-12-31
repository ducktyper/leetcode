/**
 * SOURCE: https://leetcode.com/problems/3sum
 *
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define HASH_SIZE 1000
#define BUCKET_SIZE 10

void swap(int *array, int i, int j);
void quickSort(int * array, int from, int to);
void addToNaturals(int * set, int value);
int  includeInNaturals(int * set, int value);

int** threeSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;

    int ns[numsSize];
    memcpy(ns, nums, sizeof(int) * numsSize);
    quickSort(ns, 0, numsSize - 1);

    int naturals[HASH_SIZE * BUCKET_SIZE] = {0};
    for (int i = 0; i < numsSize; i++) addToNaturals(naturals, ns[i]);

    int * matches[numsSize];
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && ns[i] == ns[i - 1]) continue;
        if (ns[i] > 0) break;

        for (int j = i + 1; j < numsSize - 1; j++)
        {
            int x = -ns[i] - ns[j];
            if (j > i + 1 && ns[j] == ns[j - 1]) continue;
            if (ns[j] > x) break;

            if (ns[j] == x ? (ns[j + 1] == x) : includeInNaturals(naturals, x))
            {
                int * m = malloc(sizeof(int) * 3);
                m[0] = ns[i];
                m[1] = ns[j];
                m[2] = x;
                matches[(*returnSize)++] = m;
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

void addToNaturals(int * set, int value)
{
    if (value <= 0) return;
    int * bucket = &set[value % HASH_SIZE * BUCKET_SIZE], i = -1;
    while (++i < BUCKET_SIZE)
    {
        if (bucket[i] == value) return;
        if (bucket[i] == 0) { bucket[i] = value; return; }
    }
    if (i == BUCKET_SIZE) { printf("Out of BUCKET_SIZE!\n"); exit(1); }
}

int includeInNaturals(int * set, int value)
{
    int * bucket = &set[value % HASH_SIZE * BUCKET_SIZE], i = -1;
    while (++i < BUCKET_SIZE) 
    {
        if (bucket[i] == 0)     return 0;
        if (bucket[i] == value) return 1;
    }
    return 0;
}
