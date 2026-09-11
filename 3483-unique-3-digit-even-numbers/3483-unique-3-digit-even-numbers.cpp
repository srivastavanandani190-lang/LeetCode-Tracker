class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count the frequency of each available digit
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        int ans = 0;
        
        // Check every possible 3-digit even number
        for (int i = 100; i <= 998; i += 2) {
            int curr = i;
            vector<int> currentCount(10, 0);
            
            // Extract digits of the current number
            while (curr > 0) {
                currentCount[curr % 10]++;
                curr /= 10;
            }
            
            // Verify if we have enough of each digit to form this number
            bool possible = true;
            for (int j = 0; j < 10; j++) {
                if (currentCount[j] > count[j]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                ans++;
            }
        }
        
        return ans;
    }
};