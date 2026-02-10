leetcode 104 : Maximum Depth of Binary Tree

class Solution {
public:
    int level(TreeNode* &root){
        if(root==nullptr) return 0;
        return 1+max(level(root->right),level(root->left));
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1+max(level(root->left),level(root->right));
    }
};
