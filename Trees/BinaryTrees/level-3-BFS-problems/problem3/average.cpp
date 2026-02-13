//Leetcode 637. Average of Levels in Binary Tree


//cpp code-

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            double sum=0;
            double res=0;
            int itr=q.size();
            for(int i=0;i<itr;i++){
                TreeNode* curr=q.front();
                sum+=curr->val;
                q.pop();
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
            res=sum/itr;
            ans.push_back(res);
        }
        return ans;
    }
};
