// leetcode 101 Symmetric Tree


class Solution {
public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        if(p->val!=q->val) return false;
        if(!isSameTree(p->left,q->left)) return false;
        if(!isSameTree(p->right,q->right)) return false;

        return true;
    }
    void invert(TreeNode* &root){
        if(root==nullptr) return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        invert(root->left);
        invert(root->right);
    }
    bool isSymmetric(TreeNode* root) {
        invert(root->right);
        return isSameTree(root->left,root->right);
    }
};

//time complexity - O(n)
//this above solution is modifying the tree which is not allowed or bad coding, we need to write a code that does not modify the code

class Solution {
public:
    bool isInvert(TreeNode* l,TreeNode* r){
        if(l==nullptr && r==nullptr) return true;
        if(l==nullptr || r==nullptr) return false;
        if(l->val!=r->val) return false;
        return isInvert(l->left,r->right) && isInvert(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return isInvert(root->left,root->right);
    }
};

// time complexity- O(n)

