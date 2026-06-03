class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s=0;
        int e=0;
        int n=nums.size();
        int total=INT_MAX;
        int sum=0;
        while(e<n){
        sum+=nums[e];
        while(sum>=target){
            total=min(total,e-s+1);
            sum-=nums[s++];
        }
        e++;
        }
        return total == INT_MAX ? 0 : total;
    }
};