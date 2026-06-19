/*
Leetcode 94, inorder using morris traversal

Key Observation:
Instead of using recursion/stack, temporarily
modify the tree by creating threads to return
to the parent after finishing the left subtree.

Time Complexity: O(n)

Space Complexity: O(1)
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr=root;
        vector<int> ans;
        while(curr!=nullptr){
            if(curr->left==nullptr){
               ans.push_back(curr->val);
               curr=curr->right;
            }else{
                TreeNode *temp=curr->left;
                while(temp->right!=nullptr) temp=temp->right;
                temp->right=curr;
                TreeNode *prev=curr;
                curr=curr->left;
                prev->left=nullptr;
            }
        }
        return ans;
    }
};
