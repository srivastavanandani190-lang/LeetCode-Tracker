class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_idx(26, 0);
        for (int i = 0; i < s.length(); i++) {
            last_idx[s[i] - 'a'] = i; // Track the last position of each character
        }
        
        vector<bool> seen(26, false);
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If the character is already included, skip it
            if (seen[c - 'a']) continue;
            
            // Maintain monotonic increasing order if possible
            while (!result.empty() && result.back() > c && last_idx[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(c);
            seen[c - 'a'] = true;
        }
        
        return result;
    }
};