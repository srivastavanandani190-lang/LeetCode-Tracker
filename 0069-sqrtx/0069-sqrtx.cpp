class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1, high = x, res = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == x) {
                return mid;
            } 
            else if (mid * mid < x) {
                res = mid;        // store possible answer
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return res;
    }
};
