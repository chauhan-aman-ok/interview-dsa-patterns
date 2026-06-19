/*
Problem:
LC 515 - Find Largest Value in Each Tree Row

Approach:
Perform level order traversal.
For every level, compute the maximum value among
all nodes present in that level and store it in
the answer.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            int maxVar=INT_MIN;
            while(size--){
                TreeNode * node=q.front();
                q.pop();
                maxVar=max(maxVar,node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxVar);
        }
        return ans;
    }
};
