class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // base case: if string length is 2*n, we have a valid combination
        if(current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // we can add '(' if we haven't used all n of them
        if(open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // we can add ')' only if we have more '(' than ')'
        if(close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
};