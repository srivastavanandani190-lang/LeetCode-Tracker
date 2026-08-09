#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        
        for (std::string s : strs) {
            std::string sortedStr = s;
            std::sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(s);
        }
        
        std::vector<std::vector<std::string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};