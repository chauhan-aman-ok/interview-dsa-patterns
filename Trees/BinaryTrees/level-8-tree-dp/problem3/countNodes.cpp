/*
Problem:
LC 2265 - Count Nodes Equal to Average of Subtree


Approach:
For every node, return:

1. Sum of subtree
2. Count of nodes in subtree

Using information returned from left and right children:

sum   = root->val + leftSum + rightSum
count = 1 + leftCount + rightCount

Check:
sum / count == root->val

If true, increment answer.

Return {sum, count} to the parent.

Time Complexity: O(n)

Space Complexity: O(h)
*/


class Solution {
public:
    int ans=0;
    pair<int,int> fun(TreeNode *root){
        if(!root) return {0,0};
        auto left=fun(root->left);
        auto right=fun(root->right);
        int sum=root->val + left.first + right.first;
        int count=1+left.second+right.second;
        if(sum/count==root->val) ans++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return ans;
    }
};
