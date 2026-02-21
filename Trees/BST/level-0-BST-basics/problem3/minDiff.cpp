//leetcode 530. Minimum Absolute Difference in BST


class Solution {
public:
    void inorder(TreeNode* root,int &prev,int &ans) {
        if (root == nullptr) return;

        inorder(root->left,prev,ans);

        if (prev != -1) {
            ans = min(ans, root->val - prev);
        }
        prev = root->val;

        inorder(root->right,prev,ans);
    }

    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr) return 0;
        int prev=-1;
        int ans=INT_MAX;
        inorder(root,prev,ans);
        return ans;
    }
};

