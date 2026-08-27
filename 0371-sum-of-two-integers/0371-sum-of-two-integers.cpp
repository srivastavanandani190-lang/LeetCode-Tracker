class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Calculate the carry. 
            // We use unsigned int to prevent overflow issues with negative numbers in C++.
            unsigned int carry = a & b;
            
            // Calculate the sum without the carry
            a = a ^ b;
            
            // Shift the carry to the left so it gets added in the next iteration
            b = carry << 1;
        }
        return a;
    }
};