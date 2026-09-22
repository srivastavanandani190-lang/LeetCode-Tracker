#include <vector>

using namespace std;

class Solution {
    struct Node {
        int prod;
        int cnt[5];
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) cnt[i] = 0;
        }
    };

    vector<Node> tree;

    // Merge two Segment Tree nodes
    Node mergeNodes(const Node& left, const Node& right, int k) {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        
        // Copy prefix counts from the left child
        for (int i = 0; i < k; ++i) {
            res.cnt[i] = left.cnt[i];
        }
        
        // Add prefix counts from the right child, offset by the left child's total product
        for (int i = 0; i < k; ++i) {
            if (right.cnt[i] > 0) {
                res.cnt[(left.prod * i) % k] += right.cnt[i];
            }
        }
        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums, int k) {
        if (start == end) {
            tree[node].prod = nums[start] % k;
            tree[node].cnt[nums[start] % k] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, nums, k);
        build(2 * node + 2, mid + 1, end, nums, k);
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2], k);
    }

    void update(int node, int start, int end, int idx, int val, int k) {
        if (start == end) {
            tree[node].prod = val % k;
            for (int i = 0; i < k; ++i) tree[node].cnt[i] = 0;
            tree[node].cnt[val % k] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val, k);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val, k);
        }
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2], k);
    }

    Node queryRange(int node, int start, int end, int L, int R, int k) {
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (R <= mid) {
            return queryRange(2 * node + 1, start, mid, L, R, k);
        }
        if (L > mid) {
            return queryRange(2 * node + 2, mid + 1, end, L, R, k);
        }
        Node leftNode = queryRange(2 * node + 1, start, mid, L, R, k);
        Node rightNode = queryRange(2 * node + 2, mid + 1, end, L, R, k);
        return mergeNodes(leftNode, rightNode, k);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        
        build(0, 0, n - 1, nums, k);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start_i = q[2];
            int x_i = q[3];

            // 1. Update the value at idx
            update(0, 0, n - 1, idx, val, k);
            
            // 2. Query the frequencies in the range [start_i, n - 1]
            Node res = queryRange(0, 0, n - 1, start_i, n - 1, k);
            
            // 3. Store the result for remainder x_i
            ans.push_back(res.cnt[x_i]);
        }

        return ans;
    }
};