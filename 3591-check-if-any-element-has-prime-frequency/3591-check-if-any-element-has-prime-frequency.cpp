class Solution {
private:
    // Helper function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count the frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Iterate through the map to check if any frequency is prime
        for (auto const& [key, count] : freq) {
            if (isPrime(count)) {
                return true; // Found a prime frequency
            }
        }
        
        return false; // No prime frequencies found
    }
};