class Solution {
public:
    int reverse(int x) {
        long long sum = 0;
        
        while (x != 0) {
            int rem = x % 10;
            x = x / 10;
            sum = sum * 10 + rem;
            
            // overflow check
            if (sum > INT_MAX || sum < INT_MIN)
                return 0;
        }
        return sum;
    }
};
