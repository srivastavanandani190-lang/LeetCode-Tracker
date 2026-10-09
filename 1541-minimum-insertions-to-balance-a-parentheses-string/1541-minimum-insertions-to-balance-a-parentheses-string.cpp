class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        stack<char> st; // Stores characters or representations of missing needs
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                // c == ')'
                // Check if there is a consecutive ')' available
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++; // Skip the next ')' since we consume it as a pair '))'
                } else {
                    // We only have a single ')', so we need to insert one more ')'
                    res++; 
                }
                
                // Now match with an open '(' if available
                if (!st.empty()) {
                    st.pop(); // Matched a '(' with '))'
                } else {
                    res++; // No matching '(', so we must insert an opening '('
                }
            }
        }
        
        // Any remaining unmatched '(' in the stack each need 2 ')'
        while (!st.empty()) {
            res += 2;
            st.pop();
        }
        
        return res;
    }
};