class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(i<nums.size()&& j<nums.size()){
           swap(nums[i],nums[j]);
           i+=2;
           j+=2;
        }
        
     return nums;
    }
};