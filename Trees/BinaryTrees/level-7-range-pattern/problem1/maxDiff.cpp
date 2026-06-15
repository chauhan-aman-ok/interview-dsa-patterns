/*
Problem: LC 1026 - Maximum Difference Between Node and Ancestor


Approach:
Maintain the minimum and maximum values encountered
along the current root-to-node path. At each node,
update the range [min, max] and propagate it to the
children. The maximum ancestor difference for a path
is given by |max - min|.

Time Complexity: O(n)

Space Complexity: O(h)
*/

class Solution {
public:
    int fun(TreeNode *root,int mn,int mx){
        if(!root){
            return abs(mn-mx);
        }
        mn=min(mn,root->val);
        mx=max(mx,root->val);

        int left=fun(root->left,mn,mx);
        int right=fun(root->right,mn,mx);

        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
       return fun(root,root->val,root->val);
    }
};



