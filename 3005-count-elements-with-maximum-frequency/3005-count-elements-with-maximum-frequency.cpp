 class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {
         unordered_map<int, int> freq;
         int n = arr.size();
         int count = 0; 
     
         for(int i = 0; i < n; i++){
             freq[arr[i]]++;
             count = max(count, freq[arr[i]]);
         }

         int num = 0;
       
         for(auto it : freq){
             if(it.second == count){
                 num += count;  
             }
         }

         return num;
    }
};