class Solution {
public:
    void rotatecw(string &str) {
        int n = str.size();
        if (n <= 1) return;
        
        char last = str[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            str[i + 1] = str[i];
        }
        str[0] = last;
    }

    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        string temp = s;

        for (int i = 0; i < s.size(); i++) {
            if (temp == goal) {
                return true;
            }
            rotatecw(temp);
        }

        return false;
    }
};