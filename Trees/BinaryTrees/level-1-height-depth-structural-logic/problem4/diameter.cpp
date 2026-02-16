//   Diameter of Binary Tree – LC 543


class Solution {
public:
    int level(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int left=0;
        int right=0;
        if(root->left!=nullptr) left=level(root->left);
        if(root->right!=nullptr) right=level(root->right);
        int rootDia=left+right;
        return max(rootDia,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};
// brute force, time complexity of this code is O(n^2)

// here is the optimized version of the above code, we will compare the diameter of previos node to every current node-

class Solution {
public:
    int level(TreeNode* root,int &diameter){
        if(root==nullptr) return 0;
        
        int left=level(root->left,diameter);
        int right=level(root->right,diameter);
        diameter=max(diameter,left+right);
        return 1+max(right,left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int dia=0;
        level(root,dia);
        return dia;
    }
};

// time complexity of the above code is O(n)

