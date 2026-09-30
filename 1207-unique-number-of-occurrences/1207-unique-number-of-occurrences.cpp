#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> countMap;
        
        // Count the occurrences of each number
        for (int num : arr) {
            countMap[num]++;
        }
        
        std::unordered_set<int> frequencies;
        
        // Check if frequencies are unique
        for (auto const& [key, value] : countMap) {
            // insert() returns a pair where the second element is a boolean 
            // indicating whether the insertion was successful (i.e., unique)
            if (!frequencies.insert(value).second) {
                return false; 
            }
        }
        
        return true;
    }
};