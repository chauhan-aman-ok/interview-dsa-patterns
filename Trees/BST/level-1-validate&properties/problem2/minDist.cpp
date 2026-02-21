// leetcode - 783. Minimum Distance Between BST Nodes

// O(n) time and O(h) space
class Solution {
public:
    void helper(TreeNode* root, int& diff, int& prev) {
        if (root == nullptr)
            return;
        helper(root -> left, diff, prev);
        if (prev != -1) {
            diff = min(diff, root -> val - prev);
        }
        prev = root -> val;
        helper(root -> right, diff, prev);
        
    }
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX;
        int prev = -1;
        helper(root, diff, prev);
        return diff;
    }
};
