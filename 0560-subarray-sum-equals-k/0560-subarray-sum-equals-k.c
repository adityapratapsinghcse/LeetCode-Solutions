#include <stdlib.h>

#define TABLE_SIZE 200003

typedef struct {
    int key;
    int value;
    int used;
} HashEntry;

int hash(int key) {
    long long h = key;
    if (h < 0)
        h = -h;

    return h % TABLE_SIZE;
}

int subarraySum(int* nums, int numsSize, int k) {

    HashEntry* table = calloc(TABLE_SIZE, sizeof(HashEntry));

    int prefix_sum = 0;
    int count = 0;

    int index = hash(0);
    table[index].key = 0;
    table[index].value = 1;
    table[index].used = 1;

    for (int i = 0; i < numsSize; i++) {

        prefix_sum += nums[i];

        int target = prefix_sum - k;

        // Search for target
        int pos = hash(target);

        while (table[pos].used) {

            if (table[pos].key == target) {
                count += table[pos].value;
                break;
            }

            pos = (pos + 1) % TABLE_SIZE;
        }

        // Add/increment prefix_sum
        pos = hash(prefix_sum);

        while (table[pos].used) {

            if (table[pos].key == prefix_sum) {
                table[pos].value++;
                break;
            }

            pos = (pos + 1) % TABLE_SIZE;
        }

        // New prefix_sum
        if (!table[pos].used) {
            table[pos].key = prefix_sum;
            table[pos].value = 1;
            table[pos].used = 1;
        }
    }

    free(table);

    return count;
}