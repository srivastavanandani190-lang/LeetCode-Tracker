class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Store knowledge in an unordered_map for O(1) lookups
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string result;
        string current_key;
        bool in_bracket = false;
        
        // Iterate through the string to evaluate the pairs
        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
                current_key = ""; // Reset the key for the new bracket pair
            } else if (c == ')') {
                in_bracket = false;
                // Look up the parsed key in our dictionary
                auto it = dict.find(current_key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } else {
                if (in_bracket) {
                    current_key += c; // Build the key string
                } else {
                    result += c;      // Append normal characters
                }
            }
        }
        
        return result;
    }
};