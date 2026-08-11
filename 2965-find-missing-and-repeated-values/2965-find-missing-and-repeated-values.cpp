#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int totalSize = n * n;
        std::vector<int> count(totalSize + 1, 0);
        
        int repeated = -1;
        int missing = -1;
        
        // Count frequencies of each number in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                count[grid[i][j]]++;
            }
        }
        
        // Find the number that appears twice and the one that appears zero times
        for (int i = 1; i <= totalSize; ++i) {
            if (count[i] == 2) {
                repeated = i;
            } else if (count[i] == 0) {
                missing = i;
            }
        }
        
        return {repeated, missing};
    }
};