class Solution {
private:
    // Helper function to check if a string is valid and count invalid brackets using a stack
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
            }
            if (count < 0) return false;  
        }
        return count == 0;
    }

    void dfs(string s, int startIndex, int leftRem, int rightRem, unordered_set<string>& result) {
        if (leftRem == 0 && rightRem == 0) {
            if (isValid(s)) {
                result.insert(s);
            }
            return;
        }

        for (int i = startIndex; i < s.length(); ++i) {
            // Skip consecutive identical characters to avoid duplicate branches
            if (i > startIndex && s[i] == s[i - 1]) continue;

            string nextStr = s.substr(0, i) + s.substr(i + 1);
            if (s[i] == '(' && leftRem > 0) {
                dfs(nextStr, i, leftRem - 1, rightRem, result);
            } else if (s[i] == ')' && rightRem > 0) {
                dfs(nextStr, i, leftRem, rightRem - 1, result);
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        // Step 1: Use a stack approach to find the exact number of misplaced '(' and ')'
        int leftRem = 0, rightRem = 0;
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push('(');
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    rightRem++; // Unmatched closing parenthesis
                }
            }
        }
        leftRem = st.size(); // Remaining unmatched opening parentheses in stack

        // Step 2: Use DFS / Backtracking to remove the required counts
        unordered_set<string> resultSet;
        dfs(s, 0, leftRem, rightRem, resultSet);

        return vector<string>(resultSet.begin(), resultSet.end());
    }
};