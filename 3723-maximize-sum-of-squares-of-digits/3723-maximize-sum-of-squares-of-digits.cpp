class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the sum is greater than the maximum possible sum of digits (9 * num)
        if (sum > 9LL * num) {
            return "";
        }
        
        int q = sum / 9;
        int r = sum % 9;
        
        string ans = "";
        ans.reserve(num);
        
        // 1. Place as many '9's as possible to maximize the score
        ans.append(q, '9');
        
        // 2. Place the remainder digit if it exists
        if (r > 0) {
            ans.push_back('0' + r);
        }
        
        // 3. Fill the remaining positions with '0's to match the exact length `num`
        ans.append(num - q - (r > 0 ? 1 : 0), '0');
        
        return ans;
    }
};