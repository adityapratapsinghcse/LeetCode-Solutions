class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int k;

    // --------------------------------------------------
    // Merge A + B
    // --------------------------------------------------
    Node mergeNode(const Node& A, const Node& B) {

        Node C;

        C.prod = (int)((long long)A.prod * B.prod % k);

        // Prefixes completely inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] = A.cnt[r];
        }

        // Prefixes = whole A + prefix of B
        for (int r = 0; r < k; r++) {

            int nr = (int)((long long)A.prod * r % k);

            C.cnt[nr] += B.cnt[r];
        }

        return C;
    }

    // --------------------------------------------------
    // Create leaf
    // --------------------------------------------------
    Node makeNode(int value) {

        Node res;

        res.prod = value % k;
        res.cnt[res.prod] = 1;

        return res;
    }

    // --------------------------------------------------
    // Solution
    // --------------------------------------------------
    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->k = k;

        int n = nums.size();

        /*
            Iterative segment tree.

            Leaves:
                tree[n ... 2*n-1]

            Parents:
                tree[1 ... n-1]
        */

        vector<Node> tree(2 * n);

        // Build leaves
        for (int i = 0; i < n; i++) {
            tree[n + i] = makeNode(nums[i]);
        }

        // Build tree
        for (int i = n - 1; i >= 1; i--) {
            tree[i] = mergeNode(
                tree[i << 1],
                tree[i << 1 | 1]
            );
        }

        // --------------------------------------------------
        // Point update
        // --------------------------------------------------
        auto update = [&](int pos, int value) {

            pos += n;

            tree[pos] = makeNode(value);

            pos >>= 1;

            while (pos >= 1) {

                tree[pos] = mergeNode(
                    tree[pos << 1],
                    tree[pos << 1 | 1]
                );

                pos >>= 1;
            }
        };

        // --------------------------------------------------
        // Range query [l, r]
        // --------------------------------------------------
        auto query = [&](int l, int r) {

            Node leftResult;
            Node rightResult;

            bool hasLeft = false;
            bool hasRight = false;

            l += n;
            r += n + 1; // make r exclusive

            while (l < r) {

                if (l & 1) {

                    if (!hasLeft) {
                        leftResult = tree[l];
                        hasLeft = true;
                    }
                    else {
                        leftResult =
                            mergeNode(leftResult, tree[l]);
                    }

                    l++;
                }

                if (r & 1) {

                    --r;

                    if (!hasRight) {
                        rightResult = tree[r];
                        hasRight = true;
                    }
                    else {
                        rightResult =
                            mergeNode(tree[r], rightResult);
                    }
                }

                l >>= 1;
                r >>= 1;
            }

            if (!hasLeft)
                return rightResult;

            if (!hasRight)
                return leftResult;

            return mergeNode(leftResult, rightResult);
        };

        // --------------------------------------------------
        // Process queries
        // --------------------------------------------------

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;

            update(index, value);

            // Query [start, n-1]
            Node res = query(start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};