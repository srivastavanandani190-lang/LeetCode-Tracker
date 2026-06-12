class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;   // change string to char

        for (char c : s) {
            if (st.empty()) {
                st.push(c);
            }
            else if (st.top() == c) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        string ans = "";
        while (!st.empty()) {   // build the answer
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());  // stack stores in reverse order
        return ans;
    }
};