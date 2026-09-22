class Solution {

    static class Node {
        int product;
        int[] cnt;

        Node(int k) {
            cnt = new int[k];
        }
    }

    int n, k;
    int[] nums;
    Node[] tree;

    public int[] resultArray(int[] nums, int k, int[][] queries) {
        this.n = nums.length;
        this.k = k;
        this.nums = nums;

        tree = new Node[4 * n];

        build(1, 0, n - 1);

        int[] ans = new int[queries.length];

        for (int q = 0; q < queries.length; q++) {

            int index = queries[q][0];
            int value = queries[q][1];
            int start = queries[q][2];
            int x = queries[q][3];

            // Persistent update
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Query [start, n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans[q] = res.cnt[x];
        }

        return ans;
    }

    // --------------------------------------------------
    // BUILD
    // --------------------------------------------------

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node] = makeLeaf(nums[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    // --------------------------------------------------
    // LEAF
    // --------------------------------------------------

    Node makeLeaf(int value) {

        Node res = new Node(k);

        res.product = value % k;

        // Only one prefix: the element itself
        res.cnt[res.product] = 1;

        return res;
    }

    // --------------------------------------------------
    // MERGE
    // --------------------------------------------------

    Node merge(Node left, Node right) {

        Node res = new Node(k);

        // Product of the complete segment
        res.product =
            (int)((long)left.product * right.product % k);

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Prefixes which contain all of left
        // followed by a prefix of right
        for (int r = 0; r < k; r++) {

            int newRemainder =
                (int)((long)left.product * r % k);

            res.cnt[newRemainder] += right.cnt[r];
        }

        return res;
    }

    // --------------------------------------------------
    // UPDATE
    // --------------------------------------------------

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {
            tree[node] = makeLeaf(value);
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(tree[node * 2],
                            tree[node * 2 + 1]);
    }

    // --------------------------------------------------
    // RANGE QUERY
    // --------------------------------------------------

    Node query(int node, int l, int r,
               int ql, int qr) {

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;

        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left =
            query(node * 2, l, mid, ql, qr);

        Node right =
            query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }
}