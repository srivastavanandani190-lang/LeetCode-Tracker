class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int t=0;
        unordered_map<int,int>freq;
        int s=0,e=0,n=nums.size(),count=0,total=0;
            while(e<n){
            if(freq[nums[e]]==0)
            //encuntered a new element so increase count by one
            count++;
            freq[nums[e]]++;
            //count>k, so start decreasing our window
            while(count>k){
                freq[nums[s]]--;
                if(freq[nums[s]]==0)
                count--;
                s++;
            }
            //count<k, so add it in our answer
            total+=e-s+1;
            e++;
        }
        s=0,e=0,count=0;
        freq.clear();
        k--;
         while(e<n){
            if(freq[nums[e]]==0)
            //encuntered a new element so increase count by one
            count++;
            freq[nums[e]]++;
            //count>k, so start decreasing our window
            while(count>k){
                freq[nums[s]]--;
                if(freq[nums[s]]==0)
                count--;
                s++;
            }
            //count<k, so add it in our answer
            total-=e-s+1;
            e++;
        }
        return total;
    }
};