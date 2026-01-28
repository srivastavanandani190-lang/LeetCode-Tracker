class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int ele=0;
        sort(nums.begin(),nums.end());
        if(n==1){
            ele=nums[0];
        }
        else{
        for(int i=0;i<n-1;i++){
          ele=nums[n/2];

        }
        }
        return ele ;
    }
};