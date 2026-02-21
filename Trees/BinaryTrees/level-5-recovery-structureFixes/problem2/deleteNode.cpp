// leetcode 450, Delete node in bst

class Solution {
public:
    int maxLeft(TreeNode* root) {
    while (root->right != nullptr) root = root->right;
    return root->val;
}

    TreeNode* del(TreeNode* root,int k){
          if(root==nullptr) return nullptr;

        if(root->val==k){
            if(root->left==nullptr && root->right==nullptr){
              return nullptr;
            }else if(root->left==nullptr) return root->right;
            else if(root->right==nullptr) return root->left;
            else{
                // two child
                int leftMax=maxLeft(root->left);
                root->val=leftMax;
                root->left=del(root->left,leftMax);
            }
        }
        if(root->val<k) root->right= del(root->right,k);
        else root->left =del(root->left,k);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root,key);
    }
};
