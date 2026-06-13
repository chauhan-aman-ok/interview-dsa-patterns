// leetcode - 105, Construct Binary Tree from Preorder and Inorder Traversal
// Time Complexity : O(n²)  
// space complexity : O(h) 


class Solution {
public:
    int idx;
    TreeNode *helper(vector<int> &pre,vector<int> &in, int beg,int end){
        if(beg>end) return nullptr;
        TreeNode * node=new TreeNode(pre[idx]);
        int i=beg;
        while(i<=pre.size()-1){
            if(node->val==in[i]) break;
            i++;
        }
        idx++;
        node->left=helper(pre,in,beg,i-1);
        node->right=helper(pre,in,i+1,end);
        return node;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        idx=0;
        return helper(pre,in,0,pre.size()-1);
    }
};
