class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum; // Set num to the new sum and repeat if it's still >= 10
        }
        return num;
    }
};