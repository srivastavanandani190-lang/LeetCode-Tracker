#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n_nodes;
    vector<vector<int>> adj;
    vector<int> tin, tout, head, parent, depth, heavy, pos;
    vector<int> tree_mask;
    int timer;

    int dfs(int u, int p, int d) {
        depth[u] = d;
        parent[u] = p;
        int size = 1, max_subtree = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int subtree = dfs(v, u, d + 1);
                size += subtree;
                if (subtree > max_subtree) {
                    max_subtree = subtree;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void decompose(int u, int h, const string& s) {
        head[u] = h;
        pos[u] = ++timer;
        if (heavy[u] != -1) {
            decompose(heavy[u], h, s);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                decompose(v, v, s);
            }
        }
    }

    void build_tree(int node, int start, int end, const string& s) {
        if (start == end) {
            return;
        }
        int mid = (start + end) / 2;
        build_tree(2 * node, start, mid, s);
        build_tree(2 * node + 1, mid + 1, end, s);
        tree_mask[node] = tree_mask[2 * node] ^ tree_mask[2 * node + 1];
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree_mask[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update_tree(2 * node, start, mid, idx, val);
        } else {
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        }
        tree_mask[node] = tree_mask[2 * node] ^ tree_mask[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree_mask[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                res ^= query_tree(1, 1, n_nodes, pos[head[u]], pos[u]);
                u = parent[head[u]];
            } else {
                res ^= query_tree(1, 1, n_nodes, pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
        }
        if (depth[u] > depth[v]) {
            res ^= query_tree(1, 1, n_nodes, pos[v], pos[u]);
        } else {
            res ^= query_tree(1, 1, n_nodes, pos[u], pos[v]);
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n_nodes = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        tin.resize(n);
        tout.resize(n);
        head.resize(n);
        parent.resize(n);
        depth.resize(n);
        heavy.assign(n, -1);
        pos.resize(n);
        timer = 0;

        dfs(0, -1, 0);
        decompose(0, 0, s);

        tree_mask.assign(4 * n + 1, 0);
        vector<int> initial_masks(n + 1);
        for (int i = 0; i < n; ++i) {
            initial_masks[pos[i]] = (1 << (s[i] - 'a'));
        }

        auto build_initial = [&](auto& self, int node, int start, int end) -> void {
            if (start == end) {
                tree_mask[node] = initial_masks[start];
                return;
            }
            int mid = (start + end) / 2;
            self(self, 2 * node, start, mid);
            self(self, 2 * node + 1, mid + 1, end);
            tree_mask[node] = tree_mask[2 * node] ^ tree_mask[2 * node + 1];
        };
        build_initial(build_initial, 1, 1, n);

        vector<bool> ans;
        for (const auto& q : queries) {
            if (q[0] == 'u') {
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q.back();
                update_tree(1, 1, n, pos[u], (1 << (c - 'a')));
            } else {
                int space1 = q.find(' ', 6);
                int space2 = q.find(' ', space1 + 1);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1));
                int mask = query_path(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};