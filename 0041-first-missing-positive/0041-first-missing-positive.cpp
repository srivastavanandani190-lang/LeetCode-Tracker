class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int x:nums){
            if(x==ans){
                ans++;
            }
        }
        return ans;
    }
};