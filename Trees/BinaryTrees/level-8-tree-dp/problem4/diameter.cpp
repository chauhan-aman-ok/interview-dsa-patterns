/*
Problem:
LC 543 - Diameter of Binary Tree

Pattern:
Tree DP

Approach:
For every node, compute the height of its left
and right subtrees.

A diameter passing through the current node is:

leftHeight + rightHeight

Update the global diameter using this value.

Return:
1 + max(leftHeight, rightHeight)

to the parent as the height of the current subtree.

Key Observation:
The diameter can pass through any node, not
necessarily the root. While computing heights,
we can simultaneously compute the diameter.

Time Complexity: O(n)

Space Complexity: O(h)

Where:
n = number of nodes
h = height of tree
*/


class Solution {
public:
int dia;
    int diameter(TreeNode *root){
       if(root==nullptr) return 0;
       int left=diameter(root->left);
       int right=diameter(root->right);
       dia=max(dia,left+right);
       return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia=0;
        diameter(root);
        return dia;
    }
};
