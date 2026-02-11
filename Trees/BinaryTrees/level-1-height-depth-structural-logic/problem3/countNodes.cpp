problem 3 : leetcode 222. Count Complete Tree Nodes

class Solution {
public:
    void level(TreeNode* root,int &count){
       if(root==nullptr) return;
       count++;
       level(root->left,count);
       level(root->right,count);
    }
    int countNodes(TreeNode* root) {
        int count=0;
        level(root,count);
        return count;
    }
};
