leetcode 113, Path Sum 2
// using backtracking ->
cpp code - 
class Solution {
public:
    void helper(TreeNode* root, vector<vector<int>> &res,vector<int> &sub,int &target, int &sum){
        if(root==nullptr) return;
        
        sum+=root->val;
        sub.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr && sum==target) res.push_back(sub);
        else{   
        helper(root->left,res,sub,target,sum);
        helper(root->right,res,sub,target,sum);
        }
        sum-=root->val; // backtrack
        sub.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> sub;
        int sum=0;
        helper(root, res,sub,targetSum,sum);
        return res;
    }
};

