// GFG - Count the nodes at distance K from leaf
/*
Approach:
Store every root-to-leaf path.
For each leaf path, move k positions upward
and insert the ancestor into a set.

Time Complexity:
O(n + L*h)

Space Complexity:
O(L*h)

Where:
L = number of leaves
h = height of tree

Worst Case (Balanced Tree):
Time  : O(n log n)
Space : O(n log n)
*/

class Solution {
public:
    vector<vector<Node*>> final;

    void fun(Node* root, vector<Node*>& sub) {
        if (!root) return;

        sub.push_back(root);

        if (!root->left && !root->right) {
            final.push_back(sub);
        } else {
            fun(root->left, sub);
            fun(root->right, sub);
        }

        sub.pop_back();
    }

    int kthFromLeaf(Node* root, int k) {
        vector<Node*> sub;
        fun(root, sub);

        unordered_set<Node*> st;

        for (auto& path : final) {
            if (path.size() > k) {
                st.insert(path[path.size() - k - 1]);
            }
        }

        return st.size();
    }
};
