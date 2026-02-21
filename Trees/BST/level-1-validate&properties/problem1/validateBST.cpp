// leetcode 98. Validate Binary Search Tree


class Solution {
public:
    void helper(TreeNode* root, vector<int> &res){
        if(root==nullptr) return ;
        helper(root->left,res);
        if(root!=nullptr) res.push_back(root->val);
        helper(root->right,res);
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return false;
        vector<int> res;
        helper(root,res);
        for(int i=0;i<res.size()-1;i++){
            if(res[i]>=res[i+1]) return false;
        }
        return true;
    }
};


// here we are using an extra space, we can do it without using extra space, the pattern will be used for this approach is  RANGE PATTERN. you can visit the range pattern directory and can see the optimized code of it
