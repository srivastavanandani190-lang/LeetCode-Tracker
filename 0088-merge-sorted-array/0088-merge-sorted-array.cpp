class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<vector<int>> A;

        vector<int> a, b;

        for (int i = 0; i < m; i++)
            a.push_back(nums1[i]);

        for (int i = 0; i < n; i++)
            b.push_back(nums2[i]);

        A.push_back(a);
        A.push_back(b);

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        int k = A.size();

        // Push first element of each array
        for (int i = 0; i < k; i++) {
            if (!A[i].empty()) {
                pq.push({A[i][0], {i, 0}});
            }
        }

        int idx = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int val = cur.first;
            int row = cur.second.first;
            int col = cur.second.second;

            nums1[idx++] = val;

            if (col + 1 < A[row].size()) {
                pq.push({A[row][col + 1], {row, col + 1}});
            }
        }
    }
};