// leetcode 1110. Delete Nodes And Return Forest
// time complexity - O(n)

//Space Complexity: O(k + h)
//where:
//k = number of nodes to delete
//h = height of the tree

                                      
class Solution {
public:
    TreeNode *deleteFun(TreeNode *root,unordered_set<int> &st,vector<TreeNode*> &ans){
        if(!root) return nullptr;

        root->left=deleteFun(root->left,st,ans);
        root->right=deleteFun(root->right,st,ans);

        if(st.find(root->val)!=st.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return nullptr;
        }else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(auto x:to_delete) st.insert(x);
        vector<TreeNode*> ans;
        deleteFun(root,st,ans);
        if(st.find(root->val)==st.end()){
            ans.push_back(root);
        }
        return ans;
    }
};
