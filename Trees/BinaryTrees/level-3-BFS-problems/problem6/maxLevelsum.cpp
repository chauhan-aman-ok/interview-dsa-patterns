/*
Problem: LC 1161 - Maximum Level Sum of a Binary Tree


Approach:
Perform BFS level by level.
For each level, calculate the sum of all node values.
Track the level having the maximum sum.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int lvl=1;
        queue<TreeNode*> q;
        q.push(root);
        int maxSum=INT_MIN;
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            while(size--){
                TreeNode *node= q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(maxSum<sum){
                ans=lvl;
                maxSum=sum;
            }
            lvl++;
        }
        return ans;
    }
};
