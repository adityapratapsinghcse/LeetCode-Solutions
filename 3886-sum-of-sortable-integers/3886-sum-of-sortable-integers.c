
#include <stdlib.h>
#include <stdbool.h>

static int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

static bool isRotation(int *nums, int *sorted,
                       int start, int k) {
    int *pattern = malloc(k * sizeof(int));
    int *lps = calloc(k, sizeof(int));

    for (int i = 0; i < k; i++)
        pattern[i] = nums[start + i];

    for (int i = 1, len = 0; i < k;) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    int i = 0, j = 0;

    while (i < 2 * k && j < k) {
        int value = sorted[start + (i % k)];

        if (value == pattern[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }

    free(pattern);
    free(lps);

    return j == k;
}

int sortableIntegers(int* nums, int numsSize) {
    int n = numsSize;
    int *sorted = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        sorted[i] = nums[i];

    qsort(sorted, n, sizeof(int), cmp);

    int ans = 0;

    for (int k = 1; k <= n; k++) {
        if (n % k != 0) continue;

        bool valid = true;

        for (int start = 0; start < n; start += k) {
            if (!isRotation(nums, sorted, start, k)) {
                valid = false;
                break;
            }
        }

        if (valid) ans += k;
    }

    free(sorted);
    return ans;
}
