/* 
Problem:
LC 814 - Binary Tree Pruning


Key Observation:
A node should be removed if its entire subtree contains no 1.

Approach:
1. Prune left subtree.
2. Prune right subtree.
3. If current node becomes a leaf with value 0,
   remove it.

Time Complexity: O(n²)
Space Complexity: O(h) 
*/




class Solution {
public:
    bool isOnePresent(TreeNode *root){
        if(root==nullptr) return false;

        if(root->val==1) return true;

        return isOnePresent(root->left) || isOnePresent(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        if(!isOnePresent(root->left)) root->left=nullptr;
        if(!isOnePresent(root->right)) root->right=nullptr;
        
        TreeNode* left =pruneTree(root->left);
        TreeNode* right=pruneTree(root->right);

        if(root->val==0 && !left && !right) return nullptr;
        return root;
    }
};

