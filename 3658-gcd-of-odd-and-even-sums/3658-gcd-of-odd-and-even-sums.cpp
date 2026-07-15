class Solution {
public:
    int gcd(int a, int b){
        if(b == 0)   
            return a;
        return gcd(b, a % b);
    }
    
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 1LL * n * n;           // n^2
        long sumEven = 1LL * n * (n + 1);    // n*(n+1)
        return gcd(sumOdd, sumEven);
    }
};