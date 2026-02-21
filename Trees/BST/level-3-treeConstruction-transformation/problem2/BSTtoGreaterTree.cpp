// leetcode 538. Convert BST to Greater Tree

class Solution {
public:
    void helper(TreeNode* &root,int &sum){
      if(root==nullptr) return;
        helper(root->right,sum);
        if(root!=nullptr){
             sum+=root->val;
             root->val=sum;
        }
        helper(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return root;
    }
};
