/*
Problem:
LC 1361 - Validate Binary Tree Nodes

Approach:
1. Ensure every node has at most one parent.
2. Find the unique root (node with no parent).
3. Perform BFS from the root.
4. Detect cycles using a visited array.
5. Verify that all n nodes are reachable.

A valid binary tree must satisfy:
- Exactly one root.
- Every node has at most one parent.
- No cycles.
- Fully connected.

Time Complexity: O(n)

Space Complexity: O(n)
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> child_to_parent;

        for(int i = 0; i < n; i++) {

            int leftC = leftChild[i];
            int rightC = rightChild[i];

            if(leftC != -1) {
                adj[i].push_back(leftC);

                if(child_to_parent.find(leftC) != child_to_parent.end())
                    return false;

                child_to_parent[leftC] = i;
            }

            if(rightC != -1) {
                adj[i].push_back(rightC);

                if(child_to_parent.find(rightC) != child_to_parent.end())
                    return false;

                child_to_parent[rightC] = i;
            }
        }

        int root = -1;

        for(int i = 0; i < n; i++) {

            if(child_to_parent.find(i) == child_to_parent.end()) {

                if(root != -1)
                    return false;

                root = i;
            }
        }

        if(root == -1)
            return false;

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(root);
        vis[root] = true;

        int count = 1;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int &v : adj[node]) {

                if(vis[v])
                    return false;

                vis[v] = true;
                count++;
                q.push(v);
            }
        }

        return count == n;
    }
};


