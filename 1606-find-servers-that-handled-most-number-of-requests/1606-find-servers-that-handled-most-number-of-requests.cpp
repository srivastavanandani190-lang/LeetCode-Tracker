#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        int n = arrival.size();
        std::set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        // Min-heap stores pairs of {release_time, server_id}
        std::priority_queue<std::pair<long long, int>, 
                            std::vector<std::pair<long long, int>>, 
                            std::greater<std::pair<long long, int>>> busy;

        std::vector<int> requestCount(k, 0);

        for (int i = 0; i < n; ++i) {
            long long startTime = arrival[i];
            long long endTime = startTime + load[i];

            // Free up servers whose tasks have finished by the current arrival time
            while (!busy.empty() && busy.top().first <= startTime) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no servers are available, drop the request
            if (available.empty()) {
                continue;
            }

            // Find the first available server >= (i % k)
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin(); // Wrap around to the beginning
            }

            int serverId = *it;
            available.erase(it);

            // Assign the request to this server
            busy.push({endTime, serverId});
            requestCount[serverId]++;
        }

        // Find the maximum number of requests handled by any server
        int maxRequests = 0;
        for (int count : requestCount) {
            maxRequests = std::max(maxRequests, count);
        }

        // Collect all servers that handled the maximum number of requests
        std::vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                busiest.push_back(i);
            }
        }

        return busiest;
    }
};