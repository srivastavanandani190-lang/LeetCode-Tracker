class Solution {
public:
    int maxScore(vector<int>& cardPoints, int K) {
        
        int sum1 = 0, sum2 = 0;
        int n = cardPoints.size() - 1;
        
        for(int i = 0; i < K; i++) {
            sum1 += cardPoints[i];
        }
        
        sum2 = sum1;
        int m = K - 1;
        
        for(int i = n; i >= (int)cardPoints.size() - K; i--) {
            sum1 -= cardPoints[m];
            sum1 += cardPoints[i];
            sum2 = max(sum2, sum1);
            m--;
        }
        
        return sum2;
    }
};