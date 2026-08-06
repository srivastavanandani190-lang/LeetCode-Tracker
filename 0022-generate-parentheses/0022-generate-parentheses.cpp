class Solution {
public:
void parenth(int n,int left ,int right,vector<string>&ans,string &temp){
    if(left+right==2*n){
        ans.push_back(temp);
        return ;
    }
    if(left<n){
        temp.push_back('(');
        parenth(n,left+1,right,ans,temp);
        temp.pop_back();
    }
     if(right<left){
        temp.push_back(')');
        parenth(n,left,right+1,ans,temp);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        // backtrack(result, "", 0, 0, n);
        parenth(n,0,0,ans,temp);
        return ans;
    }
    
// private:
//     void backtrack(vector<string>& result, string current, int open, int close, int n) {
//         // base case: if string length is 2*n, we have a valid combination
//         if(current.size() == 2 * n) {
//             result.push_back(current);
//             return;
//         }
        
//         // we can add '(' if we haven't used all n of them
//         if(open < n) {
//             backtrack(result, current + "(", open + 1, close, n);
//         }
        
//         // we can add ')' only if we have more '(' than ')'
//         if(close < open) {
//             backtrack(result, current + ")", open, close + 1, n);
// //         }
//     }
};