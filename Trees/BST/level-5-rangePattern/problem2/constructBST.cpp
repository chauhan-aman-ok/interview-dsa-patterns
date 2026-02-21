// 1008. Construct Binary Search Tree from Preorder Traversal

class Solution {
public:
    TreeNode* build(vector<int>& pre, int& idx, long long ub) {
        if (idx == pre.size() || pre[idx] > ub)  return nullptr;

        TreeNode* root = new TreeNode(pre[idx++]);

        root->left = build(pre, idx, root->val);
        root->right = build(pre, idx, ub);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder, idx, LLONG_MAX);
    }
};

