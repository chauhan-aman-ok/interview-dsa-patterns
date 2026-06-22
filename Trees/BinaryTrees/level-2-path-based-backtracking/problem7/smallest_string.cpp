/*
Problem:
LC 988 - Smallest String Starting From Leaf

Pattern:
Path Based & Backtracking

Approach:
Maintain the current root-to-node path as a string.

When a leaf node is reached:
1. Reverse the current path to obtain the
   leaf-to-root string.
2. Compare it with the current answer.
3. Update the answer if a smaller string is found.

Use backtracking to remove the current node's
character before returning to the parent.

Key Observation:
The required string is formed from leaf to root,
but DFS naturally builds the path from root to leaf.
Therefore, reverse the path at every leaf and keep
track of the lexicographically smallest string.

Time Complexity: O(n * h)

Space Complexity: O(h)

Where:
n = number of nodes
h = height of tree
*/


class Solution {
public:
    string ans="";
    void dfs(TreeNode *root,string &curr){
        if(!root) return;
        curr.push_back(root->val+'a');
        if(!root->left && !root->right){
            string path=curr;
            reverse(path.begin(),path.end());
            if(ans=="" || ans>path) ans=path;
        }else{
          dfs(root->left,curr);
          dfs(root->right,curr);
        }
        curr.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        dfs(root,curr);
        return ans;
    }
};
