/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
    void totalleaf(TreeNode* root, int &count, bool isLeft) {
    if (root == NULL) {
        return;
    }
    // Check if it's a leaf AND it came from a left branch
    if (!root->left && !root->right && isLeft) {
        count += root->val;
        return;
    }
    
    // Pass true for the left child, false for the right child
    totalleaf(root->left, count, true);
    totalleaf(root->right, count, false);
}

int sumOfLeftLeaves(TreeNode* root) {
    int count = 0;
    // The root itself is not a left child of anything, so pass false
    totalleaf(root, count, false);
    return count;
}
};