
#include <stdlib.h>

#define MOD 1000000007LL

typedef long long ll;

typedef struct {
    ll sum, sq, lazy;
} Node;

Node *st;
int *vals;
int n;

void apply(int p, int l, int r, ll v) {
    ll len = r - l + 1;

    st[p].sq = (st[p].sq + 2 * v * st[p].sum
        + (len * v % MOD) * v) % MOD;

    st[p].sum = (st[p].sum + len * v) % MOD;
    st[p].lazy = (st[p].lazy + v) % MOD;
}

void push(int p, int l, int r) {
    if (st[p].lazy == 0 || l == r) return;

    int m = (l + r) / 2;

    apply(p * 2, l, m, st[p].lazy);
    apply(p * 2 + 1, m + 1, r, st[p].lazy);

    st[p].lazy = 0;
}

void update(int p, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return;

    if (ql <= l && r <= qr) {
        apply(p, l, r, 1);
        return;
    }

    push(p, l, r);

    int m = (l + r) / 2;

    update(p * 2, l, m, ql, qr);
    update(p * 2 + 1, m + 1, r, ql, qr);

    st[p].sum = (st[p * 2].sum + st[p * 2 + 1].sum) % MOD;
    st[p].sq = (st[p * 2].sq + st[p * 2 + 1].sq) % MOD;
}

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int findIndex(int x, int *a, int size) {
    int l = 0, r = size - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

int sumCounts(int* nums, int numsSize) {
    n = numsSize;

    int *sorted = malloc(n * sizeof(int));
    int *last = malloc(n * sizeof(int));
    st = calloc(4 * n + 5, sizeof(Node));

    for (int i = 0; i < n; i++)
        sorted[i] = nums[i];

    qsort(sorted, n, sizeof(int), cmp);

    int size = 0;

    for (int i = 0; i < n; i++) {
        if (size == 0 || sorted[i] != sorted[size - 1])
            sorted[size++] = sorted[i];
    }

    for (int i = 0; i < size; i++)
        last[i] = -1;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int id = findIndex(nums[i], sorted, size);
        int prev = last[id];

        update(1, 0, n - 1, prev + 1, i);

        ans = (ans + st[1].sq) % MOD;

        last[id] = i;
    }

    free(sorted);
    free(last);
    free(st);

    return (int)ans;
}
