class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or numbers ending with 0 (except 0) are not palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int rev = 0;

        // Reverse only half of the number
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        // For even length: x == rev
        // For odd length: x == rev / 10
        return (x == rev || x == rev / 10);
    }
};
