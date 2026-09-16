class Solution {
private:
    int MOD = 1e9 + 7;

    // Function to calculate (base^exp) % MOD in O(log exp) time
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Function to find modular inverse of n under MOD
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int numberOfSets(int n, int k) {
        // We need to calculate C(n + k - 1, 2 * k) % MOD
        int total_spaces = n + k - 1;
        int dividers = 2 * k;
        
        if (total_spaces < dividers) return 0;
        
        long long num = 1; // Numerator
        long long den = 1; // Denominator
        
        for (int i = 0; i < dividers; ++i) {
            num = (num * (total_spaces - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        
        // C(n, k) = (Numerator * modInverse(Denominator)) % MOD
        return (num * modInverse(den)) % MOD;
    }
};