class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Store queries with their original indices
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        // Sort queries and logs by time
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int left = 0, right = 0;
        int activeServers = 0;
        unordered_map<int, int> serverCount;
        
        for (auto& q : sortedQueries) {
            int queryTime = q.first;
            int originalIdx = q.second;
            int windowStart = queryTime - x;
            int windowEnd = queryTime;
            
            // Add logs that fall within or before the windowEnd
            while (right < logs.size() && logs[right][1] <= windowEnd) {
                if (serverCount[logs[right][0]] == 0) {
                    activeServers++;
                }
                serverCount[logs[right][0]]++;
                right++;
            }
            
            // Remove logs that fall before windowStart
            while (left < right && logs[left][1] < windowStart) {
                serverCount[logs[left][0]]--;
                if (serverCount[logs[left][0]] == 0) {
                    activeServers--;
                }
                left++;
            }
            
            // Total servers minus servers with at least one request equals zero-request servers
            ans[originalIdx] = n - activeServers;
        }
        
        return ans;
    }
};