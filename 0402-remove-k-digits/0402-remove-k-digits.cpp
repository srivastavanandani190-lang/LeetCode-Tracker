#include <string>
#include <algorithm>

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        
        for (char digit : num) {
            // Remove larger digits from the stack to maintain an increasing order
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }
            // Avoid pushing leading zeros when the stack is empty
            if (!st.empty() || digit != '0') {
                st.push_back(digit);
            }
        }
        
        // If we still need to remove digits, pop from the end
        while (!st.empty() && k > 0) {
            st.pop_back();
            k--;
        }
        
        // If the result is empty, return "0"
        return st.empty() ? "0" : st;
    }
};