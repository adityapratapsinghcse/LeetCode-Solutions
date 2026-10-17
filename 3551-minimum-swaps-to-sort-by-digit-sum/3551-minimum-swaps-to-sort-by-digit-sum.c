
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int sum;
    int num;
    int index;
} Element;

int digitSum(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int compare(const void *a, const void *b) {
    const Element *x = (const Element *)a;
    const Element *y = (const Element *)b;

    if (x->sum != y->sum)
        return (x->sum > y->sum) - (x->sum < y->sum);

    if (x->num != y->num)
        return (x->num > y->num) - (x->num < y->num);

    return (x->index > y->index) - (x->index < y->index);
}

int minSwaps(int* nums, int numsSize) {
    int n = numsSize;

    Element *arr = malloc(n * sizeof(Element));
    bool *visited = calloc(n, sizeof(bool));

    if (arr == NULL || visited == NULL) {
        free(arr);
        free(visited);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        arr[i].sum = digitSum(nums[i]);
        arr[i].num = nums[i];
        arr[i].index = i;
    }

    qsort(arr, n, sizeof(Element), compare);

    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || arr[i].index == i)
            continue;

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = arr[j].index;
            cycleSize++;
        }

        if (cycleSize > 1)
            swaps += cycleSize - 1;
    }

    free(arr);
    free(visited);

    return swaps;
}
