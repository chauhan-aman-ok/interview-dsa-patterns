/*
Problem: LC 623 - Add One Row to Tree

Pattern:
Tree Modification / Recovery

Approach:
Traverse to depth-1.
Insert new nodes.
Reconnect original subtrees.

Time Complexity: O(n)
Space Complexity: O(h)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * fun(TreeNode* root, int val, int depth,int currDep){
        if(!root) return root;

        if(currDep==depth-1){
            TreeNode *leftsub=root->left;
            TreeNode *rightsub=root->right;

            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            
            root->left->left=leftsub;
            root->right->right=rightsub;
            return root;
        }

        root->left=fun(root->left,val,depth,currDep+1);
        root->right=fun(root->right,val,depth,currDep+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        int currDep=1;
        
        return fun(root,val,depth,currDep);;
    }
};
