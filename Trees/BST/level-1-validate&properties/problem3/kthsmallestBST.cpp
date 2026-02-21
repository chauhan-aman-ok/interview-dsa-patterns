

// leetcode 230. Kth Smallest Element in a BST

class Solution {
public:
    void helper(TreeNode* root,vector<int> &res){
        if(root==nullptr) return;
        helper(root->left,res);
        if(root!=nullptr) res.push_back(root->val);
        helper(root->right,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        helper(root,res);

        return res[k-1];
    }
};

// the above code using an extra space, space complexity is -> S.C. - O(n)

// we can do it in O(n) space complexity->

class Solution {
public:
    void helper(TreeNode* root,int &count,int &k){
        if(root==nullptr) return;
        helper(root->left,count,k);
        count++;
        if(count==k){
            return root->val;
        }
        helper(root->right,count,k);
    }
    int kthSmallest(TreeNode* root, int k) {
       int count=0;
       return  helper(root,count,k);
        
    }
};



