leetcode - 129. Sum Root to Leaf Numbers


//cpp code -
class Solution {
public:
    void helper(TreeNode* root,string &sub,vector<string> &res){
         if(root==nullptr) return;
        sub+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr) res.push_back(sub);
        else{
            helper(root->left,sub,res);
            helper(root->right,sub,res);
        }
        sub.resize(sub.size()-to_string(root->val).size());
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        string s="";
        vector<string> res;
        helper(root,s,res);
        for(int i=0;i<res.size();i++){
            sum+=stoi(res[i]);
        }
        return sum;
    }
};
