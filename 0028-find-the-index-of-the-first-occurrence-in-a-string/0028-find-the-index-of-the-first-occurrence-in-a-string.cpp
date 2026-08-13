// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         return haystack.find(needle);
//     }
// };
class Solution {
public:
  
    int strStr(string haystack, string needle) {
      // code here
       int n = haystack.size();
        int m = needle.size();
        
         
        if (m > n) return -1;
        
        
        for (int i = 0; i <= n ; i++) {
            
            if (haystack.substr(i, m) == needle) {
                return i;  
            }
        }
        
        return -1; 
    }
};
