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
    int matchCount = 0;
    
    // Helper function returns {sum, count}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        
        // Post-order traversal: visit left, then right
        pair<int, int> leftSubtree = dfs(node->left);
        pair<int, int> rightSubtree = dfs(node->right);
        
        // Calculate sum and count for the current subtree
        int currentSum = leftSubtree.first + rightSubtree.first + node->val;
        int currentCount = leftSubtree.second + rightSubtree.second + 1;
        
        // Check if the average equals the node's value (integer division inherently rounds down)
        if (currentSum / currentCount == node->val) {
            matchCount++;
        }
        
        return {currentSum, currentCount};
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchCount;
    }
};