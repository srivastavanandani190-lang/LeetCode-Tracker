class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1}); // cost, node, consecutive count

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            long long cost = cur[0];
            int u = cur[1];
            int cnt = cur[2];

            if (cost > dist[u][cnt]) continue;

            for (auto &[v, w] : adj[u]) {
                int newCnt;

                if (labels[v] == labels[u])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if (newCnt > k) continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCnt]) {
                    dist[v][newCnt] = newCost;
                    pq.push({newCost, v, newCnt});
                }
            }
        }

        long long ans = INF;

        for (int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        return ans == INF ? -1 : (int)ans;
    }
};