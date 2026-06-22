/*
Problem:
LC 513 - Find Bottom Left Tree Value

Pattern:
Height / Depth Structural Logic

Approach 1 (DFS):
Track the deepest node encountered during a
preorder traversal (Root → Left → Right).
The first node visited at a new depth becomes
the candidate answer.

Time Complexity: O(n)
Space Complexity: O(h)
*/


class Solution {
public:
    int maxDepth;
    int ans;
    void dfs(TreeNode *root, int currDepth){
        if(!root) return;
        if(currDepth>maxDepth){
            maxDepth=currDepth;
            ans=root->val;
        }
        dfs(root->left,currDepth+1);
        dfs(root->right,currDepth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        maxDepth=-1;
        dfs(root,0);
        return ans;
    }
};
