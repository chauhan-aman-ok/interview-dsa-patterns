/*
Problem:
LC 513 - Find Bottom Left Tree Value



Approach 2 (BFS):
Perform level order traversal.
The first node of the last level is the answer.

Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
      queue<TreeNode *> q;
      q.push(root);
      int ans=0;
      while(!q.empty()){
        int size=q.size();
        ans=q.front()->val;
        while(size--){
            TreeNode *currNode=q.front();
            q.pop();
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
      }
      return ans;
    }
};
