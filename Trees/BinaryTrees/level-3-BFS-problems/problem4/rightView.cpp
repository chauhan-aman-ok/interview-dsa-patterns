//leetcode 199. Binary Tree Right Side View

//cpp code-

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int itr=q.size();
            for(int i=0;i<itr;i++){
               TreeNode* curr=q.front();
               if(i==itr-1) res.push_back(curr->val);
               q.pop();
               if(curr->left!=nullptr) q.push(curr->left);
               if(curr->right!=nullptr) q.push(curr->right);
            }
        }
        return res;
    }
};

