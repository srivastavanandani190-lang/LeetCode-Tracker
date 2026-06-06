class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxe=0;
        for(int i=0;i<n;i++){
            maxe=max(maxe,nums[i]);
        }
        int e=0,s=0,count=0;
        long long total=0;
        while(e<n){
            if(nums[e]==maxe)
                count++;
            while(count==k){
                total+=n-e;
                if(nums[s]==maxe){
                    count--;
                }
                s++;
            }
            
            e++;
        }
        return total;
    }
};