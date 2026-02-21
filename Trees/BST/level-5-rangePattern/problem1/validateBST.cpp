// leetcode 98. Validate Binary Search Tree
// optimized code,  no extra space used, space complexity - O(logn)-> recursion stack used
// time complexity - o(n)


class Solution {
public:
    bool valid(TreeNode* root,long long lower,long long higher){
        if(root==nullptr) return true;
        if(root->val <=lower || root->val >= higher) return false;
        return valid(root->left,lower,root->val) && valid(root->right,root->val,higher);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
};
