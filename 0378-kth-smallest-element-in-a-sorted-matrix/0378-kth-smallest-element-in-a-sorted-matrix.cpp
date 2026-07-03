class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({matrix[0][0], {0, 0}});
        vis[0][0] = 1;

        while (k-1) {

            auto it = pq.top();
            pq.pop();

            int i = it.second.first;
            int j = it.second.second;

            // Push right element
            if (j + 1 < n && !vis[i][j + 1]) {
                pq.push({matrix[i][j + 1], {i, j + 1}});
                vis[i][j + 1] = 1;
            }

            // Push down element
            if (i + 1 < n && !vis[i + 1][j]) {
                pq.push({matrix[i + 1][j], {i + 1, j}});
                vis[i + 1][j] = 1;
            }
            k--;
            
        }

        return pq.top().first;
    }
};