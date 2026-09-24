class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int rem=0;int sum=0;
            while(nums[i]){
                rem=nums[i]%10;
                sum+=rem;
                nums[i]/=10;
            }
            ans[i]=sum;
            sum=0;
        }
        for(int i=0;i<n;i++){
            if(ans[i]==i){
                return i;
            }
        }
        return -1;
    }
};