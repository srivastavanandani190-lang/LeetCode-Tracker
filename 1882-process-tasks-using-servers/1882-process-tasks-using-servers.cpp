#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // Min-heap for available servers: stores {weight, index}
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> available_servers;
        
        // Min-heap for busy servers: stores {free_time, index}
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> busy_servers;
        
        for (int i = 0; i < n; ++i) {
            available_servers.push({servers[i], i});
        }
        
        std::vector<int> ans(m);
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            current_time = std::max(current_time, (long long)j);
            
            // If no servers are available, fast-forward time to when the next server becomes free
            if (available_servers.empty()) {
                current_time = std::max(current_time, busy_servers.top().first);
            }
            
            // Free up all servers that finish by current_time
            while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                int idx = busy_servers.top().second;
                busy_servers.pop();
                available_servers.push({servers[idx], idx});
            }
            
            // Assign the task to the best available server
            auto [weight, idx] = available_servers.top();
            available_servers.pop();
            
            ans[j] = idx;
            busy_servers.push({current_time + tasks[j], idx});
        }
        
        return ans;
    }
};