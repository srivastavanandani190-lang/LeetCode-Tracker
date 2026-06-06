class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int t=0;
        unordered_map<int,int>freq;
        int s=0,e=0,n=nums.size(),count=0,total=0;
        while(e<n){
            freq[nums[e]]++;
            if(freq[nums[e]]==1){
                count++;
            }
            while(count==k){
                total+=n-e;
                freq[nums[s]]--;
                if(freq[nums[s]]==0){
                    count--;
                }
                s++;

            }
            e++;
        }
        s=0,e=0,count=0;
        freq.clear();
        k++;
         while(e<n){
            freq[nums[e]]++;
            if(freq[nums[e]]==1){
                count++;
            }
            while(count==k){
                total-=n-e;
                freq[nums[s]]--;
                if(freq[nums[s]]==0){
                    count--;
                }
                s++;

            }
            e++;
        }
        return total;
    }
};