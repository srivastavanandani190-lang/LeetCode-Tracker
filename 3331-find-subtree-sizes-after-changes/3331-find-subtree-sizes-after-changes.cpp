class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> origAdj(n);
        for (int i = 1; i < n; ++i) {
            origAdj[parent[i]].push_back(i);
        }

        vector<int> lastSeen(26, -1);
        vector<int> newParent = parent;

        auto findParentsDfs = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = lastSeen[c];
            if (prev != -1) {
                newParent[u] = prev;
            }
            lastSeen[c] = u;
            for (int v : origAdj[u]) {
                self(self, v);
            }
            lastSeen[c] = prev;
        };

        findParentsDfs(findParentsDfs, 0);

        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; ++i) {
            finalAdj[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 1);
        auto calcSizeDfs = [&](auto& self, int u) -> int {
            int sz = 1;
            for (int v : finalAdj[u]) {
                sz += self(self, v);
            }
            return answer[u] = sz;
        };

        calcSizeDfs(calcSizeDfs, 0);
        return answer;
    }
};