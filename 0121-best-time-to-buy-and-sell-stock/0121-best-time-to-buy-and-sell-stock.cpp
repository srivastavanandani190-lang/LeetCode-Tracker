class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar=prices[0];
        int res=0;
        for(int i=0;i<prices.size();i++){
            minsofar=min(minsofar,prices[i]);
            res=max(res,prices[i]-minsofar);
        }
        return res;
    }
};