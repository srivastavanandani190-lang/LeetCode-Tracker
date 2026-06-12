class Solution {
public:
    string build(string str) {
        string res;
        
        for (char ch : str) {
            if (ch != '#') {
                res.push_back(ch);
            } else if (!res.empty()) {
                res.pop_back();
            }
        }
        
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};