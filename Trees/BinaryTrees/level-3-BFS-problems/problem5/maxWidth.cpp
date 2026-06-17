/*
Problem:
LC 662 - Maximum Width of Binary Tree


For a node at index i:
  left child  = 2*i + 1
  right child = 2*i + 2

For every level:  width = lastIndex - firstIndex + 1

Track the maximum width across all levels.

Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        unsigned long long maxWidth=0;
        while(!q.empty()){
            unsigned long long size=q.size();
            unsigned long long l=q.front().second;
            unsigned long long r=q.back().second;
            maxWidth=max(maxWidth,r-l+1);
            while(size--){
                 TreeNode * node=q.front().first;
                 unsigned long long i=q.front().second;
                 q.pop();
                 if(node->left) q.push({node->left,2*i+1});
                 if(node->right) q.push({node->right,2*i+2});
            }
        }
        return maxWidth;
    }
};

