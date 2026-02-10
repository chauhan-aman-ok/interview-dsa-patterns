Iorder traversal (DFS)
leetcode - 94
// using recursion _ 


class Solution {
public:
   void helper(TreeNode* &r,vector<int>& res){
    if(r==nullptr) return;
    helper(r->left,res);
    res.push_back(r->val);
    helper(r->right,res);
   }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
};



// iterative approach -

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* temp=root;
        if(root==nullptr) return res;
        while(temp!=nullptr || !st.empty()){
           while(temp!=nullptr){
            st.push(temp);
            temp=temp->left;
           }

           temp=st.top();
           st.pop();
           res.push_back(temp->val);
           temp=temp->right;
        }
        return res;
}

