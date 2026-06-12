class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0, score = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (s[i - 1] == '(') {   // found "()"
                    score += (1 << depth);
                }
            }
        }

        return score;
    }
};