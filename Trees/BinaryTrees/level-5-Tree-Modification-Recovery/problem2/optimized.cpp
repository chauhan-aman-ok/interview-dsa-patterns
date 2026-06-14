/*
LC 814 - Binary Tree Pruning

Top-Down Version:
- Uses isOnePresent() to inspect subtrees.
- Time: O(n²)
- Space: O(h)

Bottom-Up Version (Optimal):
- Postorder DFS.
- Children are pruned first.
- Parent decides whether to survive.
- Time: O(n)
- Space: O(h)
*/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr) return root;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);

        if(root->val==0 && !root->left && !root->right) return nullptr;
        return root;
    }
};


