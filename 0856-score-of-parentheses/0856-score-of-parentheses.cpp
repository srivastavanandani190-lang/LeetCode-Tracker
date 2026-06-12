class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int curr = st.top();
                st.pop();

                int prev = st.top();
                st.pop();

                if (curr == 0)
                    st.push(prev + 1);      // "()"
                else
                    st.push(prev + 2 * curr); // "(A)"
            }
        }

        return st.top();
    }
};