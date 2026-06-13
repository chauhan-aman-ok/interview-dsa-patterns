// leetcode - 236. Lowest Common Ancestor of a Binary Tree

//Time Complexity: O(n)

// Space Complexity: O(h)



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode *root,TreeNode*p,TreeNode *q,TreeNode *&n){
        if(!root) return 0;
        int left=helper(root->left,p,q,n);
        int right=helper(root->right,p,q,n);
        int total=left+right;
        if(root==p || root==q) total++;
        if(total>1 && !n){
            n=root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *n=nullptr;
        helper(root,p,q,n);
        return n;
    }
};
