PostOrder traversal (DFS)

// recursive approach -
class Solution {
public:
    void helper(TreeNode*& r, vector<int>& res) {
        if (r == nullptr)
            return;
        helper(r->left, res);
        helper(r->right, res);
        res.push_back(r->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};

// iterative approach - 

 vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* lastVisited=nullptr;
        TreeNode* curr=root;
        stack<TreeNode*> st;
        vector<int> res;
        while(curr!=nullptr || !st.empty()){
            while(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }
            TreeNode* topNode=st.top();
            if(topNode->right!=nullptr && topNode->right!=lastVisited){
                curr=topNode->right;
            }else{
               res.push_back(topNode->val);
               lastVisited=topNode;
               st.pop();
            }
        }
        return res;
 }



