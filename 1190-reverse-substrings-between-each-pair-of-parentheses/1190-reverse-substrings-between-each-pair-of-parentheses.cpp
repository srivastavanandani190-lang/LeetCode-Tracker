class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string result = "";
        
        for (char c : s) {
            if (c == '(') {
                // Store the current length of the result string. 
                // This marks the starting index of the substring to be reversed later.
                st.push(result.length());
            } else if (c == ')') {
                // Get the starting index of the most recent open parenthesis
                int start = st.top();
                st.pop();
                // Reverse the substring from 'start' to the end of the current result string
                reverse(result.begin() + start, result.end());
            } else {
                // Append normal characters to the result
                result += c;
            }
        }
        
        return result;
    }
};