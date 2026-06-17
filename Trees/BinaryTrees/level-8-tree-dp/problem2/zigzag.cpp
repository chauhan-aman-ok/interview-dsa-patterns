/*
Problem:
LC 1372 - Longest ZigZag Path in a Binary Tree

Pattern: Tree DP

Approach: Maintain two states at every node:

left  = length of ZigZag path if the previous move was towards the left.

right = length of ZigZag path if the previous move was towards the right.

When moving left: left = right + 1

When moving right: right = left + 1

Track the maximum ZigZag length encountered during the traversal.

Time Complexity: O(n)

Space Complexity: O(h)
*/


class Solution {
public:
    int maxpath=0;
    void fun(TreeNode *root,int left,int right){
        if(!root) return;
        maxpath=max({maxpath,left,right});
        fun(root->left,right+1,0);
        fun(root->right,0,left+1);
    }
    int longestZigZag(TreeNode* root) {
        fun(root,0,0);
        return maxpath;
    }
};

