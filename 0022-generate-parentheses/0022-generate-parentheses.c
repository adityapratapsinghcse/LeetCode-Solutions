
#include <stdlib.h>
#include <string.h>

void backtrack(int n, int open, int close, int pos,
               char *current, char **result, int *count) {
    // Base case
    if (pos == 2 * n) {
        current[pos] = '\0';
        result[*count] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*count], current);
        (*count)++;
        return;
    }

    // Add opening bracket
    if (open < n) {
        current[pos] = '(';
        backtrack(n, open + 1, close, pos + 1,
                  current, result, count);
    }

    // Add closing bracket
    if (close < open) {
        current[pos] = ')';
        backtrack(n, open, close + 1, pos + 1,
                  current, result, count);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    // Maximum number of valid combinations is the nth Catalan number
    int capacity = 1;
    for (int i = 0; i < n; i++) {
        capacity = capacity * 2 * (2 * i + 1) / (i + 2);
    }

    char **result = (char **)malloc(capacity * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    int count = 0;

    backtrack(n, 0, 0, 0, current, result, &count);

    free(current);
    *returnSize = count;
    return result;
}