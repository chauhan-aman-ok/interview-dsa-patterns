/*

Problem:
LC 124 - Binary Tree Maximum Path Sum

Pattern:
Tree DP


State:
dp(node) = Maximum downward path sum
starting from the current node.

Approach:
1. Recursively obtain answers from left and right subtrees.
2. Compute all possible path configurations through the current node.
3. Update global answer.
4. Return the best extendable path to the parent.

Time Complexity:
O(n)

Space Complexity:
O(h)

Where:
n = number of nodes
h = height of tree
*/


class Solution {
public:
    int fun(TreeNode *root,int &maxSum){
        if(!root) return 0;
        int left=fun(root->left,maxSum);
        int right=fun(root->right,maxSum);
          
        int case1=left+right+root->val; // niche hi maximum answer mil gya
        int case2=max(left,right)+root->val; // ya to left ya fir right
        int case3=root->val; // only root acha h

        maxSum=max({maxSum,case1,case2,case3});
        return max(case2,case3);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        fun(root,maxSum);
        return maxSum;
    }
};


