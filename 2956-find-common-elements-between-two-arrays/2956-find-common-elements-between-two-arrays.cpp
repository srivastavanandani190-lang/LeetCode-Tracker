#include <vector>

class Solution {
public:
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Since elements are between 1 and 100, a fixed-size lookup array is optimal
        std::vector<bool> existsInNums1(101, false);
        std::vector<bool> existsInNums2(101, false);
        
        // Mark elements that exist in nums1
        for (int num : nums1) {
            existsInNums1[num] = true;
        }
        
        // Mark elements that exist in nums2
        for (int num : nums2) {
            existsInNums2[num] = true;
        }
        
        int answer1 = 0;
        int answer2 = 0;
        
        // Count how many elements of nums1 exist in nums2
        for (int num : nums1) {
            if (existsInNums2[num]) {
                answer1++;
            }
        }
        
        // Count how many elements of nums2 exist in nums1
        for (int num : nums2) {
            if (existsInNums1[num]) {
                answer2++;
            }
        }
        
        return {answer1, answer2};
    }
};