/*
Problem:
Count the Nodes at Distance K from Leaf

Pattern:
Path Based & Backtracking

Folder:
level-2-path-based-backtracking

Sub-pattern:
Root-to-Leaf Path Tracking

Approach:
Maintain the current root-to-node path during DFS.

When a leaf node is reached:
- Move k positions upward in the path.
- Add that ancestor node to a set.

The set ensures that the same node is counted
only once even if it is at distance k from
multiple leaves.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class Solution {
public:
    unordered_set<Node*> st;
    
    void dfs(Node* root, vector<Node*>& path, int k) {
        if (!root) return;

        path.push_back(root);

        if (!root->left && !root->right) {
            if (path.size() > k) {
                st.insert(path[path.size() - k - 1]);
            }
        } else {
            dfs(root->left, path, k);
            dfs(root->right, path, k);
        }

        path.pop_back();
    }

    int kthFromLeaf(Node* root, int k) {
        vector<Node*> path;
        dfs(root, path, k);
        return st.size();
    }
};
