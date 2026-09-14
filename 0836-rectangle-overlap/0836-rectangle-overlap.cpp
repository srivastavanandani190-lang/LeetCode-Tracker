class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // A rectangle is represented as [x1, y1, x2, y2]
        // Check if the rectangles DO NOT overlap. 
        // If they don't, one must be strictly left, right, below, or above the other.
        
        bool isLeft = rec1[2] <= rec2[0];
        bool isRight = rec1[0] >= rec2[2];
        bool isBelow = rec1[3] <= rec2[1];
        bool isAbove = rec1[1] >= rec2[3];
        
        // If any of these conditions are true, they do not overlap
        return !(isLeft || isRight || isBelow || isAbove);
    }
};