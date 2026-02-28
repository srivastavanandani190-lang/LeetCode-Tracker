class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        // Step 1: Extract words
        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += c;
            }
        }

        // Add last word if exists
        if (!temp.empty())
            words.push_back(temp);

        // Step 2: Reverse word order
        reverse(words.begin(), words.end());

        // Step 3: Join with single space
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};