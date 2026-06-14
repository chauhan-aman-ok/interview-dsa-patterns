/* Problem:
LC 366 - Find Leaves of Binary Tree


Approach:
1. Compute subtree height using postorder DFS.
2. Group nodes by height.
3. Return groups in increasing height order.

Time Complexity: O(n log h)
Space Complexity: O(n + h) */


/*
LeetCode 366 - Find Leaves of Binary Tree

Problem Statement:

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

1. Collect all the leaf nodes.
2. Remove all the leaf nodes.
3. Repeat until the tree is empty.

Return a list of lists where:
- The first list contains the original leaf nodes.
- The second list contains the new leaf nodes after removing the first set.
- And so on.

Example 1:

Input:
        1
       / \
      2   3
     / \
    4   5

Output:
[[4,5,3],[2],[1]]

Explanation:
Round 1 -> remove leaves [4,5,3]
Round 2 -> remove leaves [2]
Round 3 -> remove leaves [1]

Example 2:

Input:
    1

Output:
[[1]]

Constraints:
- Number of nodes in the tree is in the range [1, 100].
- -100 <= Node.val <= 100
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    public:

        int depth(TreeNode * root, map < int, vector < int >> & mp) {

            if (root == nullptr) return 0;
            int left = depth(root -> left, mp);
            int right = depth(root -> right, mp);

            int dep = 1 + max(left, right);

            mp[dep].push_back(root -> val);

            return dep;
        }
    vector < vector < int >> findLeaves(TreeNode * root) {
        // WRITE YOUR SOLUTION HERE 
        map < int, vector < int >> mp;
        depth(root, mp);
        vector < vector < int >> ans;
        map < int, vector < int >> ::iterator itr;

        for (itr = mp.begin(); itr != mp.end(); itr++) {
            ans.push_back(itr -> second);
        }

        return ans;
    }
};

// Helper function to print answer
void printAnswer(vector < vector < int >> & ans) {
    cout << "[\n";

    for (auto & level: ans) {
        cout << "  [";

        for (int i = 0; i < level.size(); i++) {
            cout << level[i];

            if (i + 1 < level.size())
                cout << ", ";
        }

        cout << "]\n";
    }

    cout << "]\n";
}

// ==================================================
// TEST CASE 1
// ==================================================
TreeNode * buildTestCase1() {

    /*
            1
           / \
          2   3
         / \
        4   5

    Expected:
    [[4,5,3],[2],[1]]
    */

    TreeNode * root = new TreeNode(1);

    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);

    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);

    return root;
}

// ==================================================
// TEST CASE 2
// ==================================================
TreeNode * buildTestCase2() {

    /*
        1

    Expected:
    [[1]]
    */

    return new TreeNode(1);
}

// ==================================================
// TEST CASE 3
// ==================================================
TreeNode * buildTestCase3() {

    /*
            1
           /
          2
         /
        3
       /
      4

    Expected:
    [[4],[3],[2],[1]]
    */

    TreeNode * root = new TreeNode(1);

    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(3);
    root -> left -> left -> left = new TreeNode(4);

    return root;
}

// ==================================================
// TEST CASE 4
// ==================================================
TreeNode * buildTestCase4() {

    /*
              1
            /   \
           2     3
          / \   / \
         4  5  6   7

    Expected:
    [[4,5,6,7],[2,3],[1]]
    */

    TreeNode * root = new TreeNode(1);

    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);

    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);

    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    return root;
}

int main() {

    Solution obj;

    vector < TreeNode * > tests = {
        buildTestCase1(),
        buildTestCase2(),
        buildTestCase3(),
        buildTestCase4()
    };

    for (int i = 0; i < tests.size(); i++) {

        cout << "\nTest Case " << i + 1 << ":\n";

        vector < vector < int >> ans = obj.findLeaves(tests[i]);

        printAnswer(ans);
    }

    return 0;
}

