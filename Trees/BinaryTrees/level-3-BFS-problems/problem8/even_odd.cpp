/*
Problem:
LC 1609 - Even Odd Tree

Pattern:
Tree Validation

Approach:
Perform level order traversal (BFS).

For every level:

Even Level:
1. All node values must be odd.
2. Values must be strictly increasing.

Odd Level:
1. All node values must be even.
2. Values must be strictly decreasing.

Maintain the previous value for each level and
validate the ordering constraints while traversing.

If any condition is violated, return false.

Key Observation:
The problem is not asking to compute something,
but to verify whether the tree satisfies a set of
rules level by level.

Time Complexity: O(n)

Space Complexity: O(n)

Where:
n = number of nodes
*/


class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int lvl=0;

        while(!q.empty()){
            int size=q.size();
            int prev;
            bool evenLvl;
            if(lvl%2==0){
               prev=INT_MIN;
               evenLvl=true;
            }else{
                prev=INT_MAX;
                evenLvl=false;
            }

            while(size--){

                TreeNode *currNode= q.front();
                q.pop();
                
                if(evenLvl){
                   if(currNode->val%2==0) return false;
                   if(prev>=currNode->val) return false;
                }else{
                    if(currNode->val%2!=0) return false;
                   if(prev<=currNode->val) return false;
                }

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                
                
                prev=currNode->val;
            }
            lvl++;
        }
        return true;
    }
};
