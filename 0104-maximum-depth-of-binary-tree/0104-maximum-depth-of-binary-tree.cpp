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
    int maxDepth(TreeNode* root) {
        // Base case: an empty subtree contributes -1 to the edge count
        if (root == NULL) {
            return 0;
        }
        
        // Count 1 edge for the current step plus the maximum depth of the subtrees
        return 1 + max(maxDepth(root->left), maxDepth(root->right));

    }
};