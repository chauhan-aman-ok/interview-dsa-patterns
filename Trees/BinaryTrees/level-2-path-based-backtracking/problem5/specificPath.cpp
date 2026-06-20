// gfg - Paths from root with a specified sum
// Time complexity : O(n)
// Space complexity : O(h)


class Solution {
  public:
    vector<vector<int>> ans;
    void fun(Node *root,int target,int sum,vector<int> &sub){
        if(!root) return ;
        
        sum+=root->key;
        sub.push_back(root->key);
        if(sum==target){
            ans.push_back(sub);
        }
        fun(root->left,target,sum,sub);
        fun(root->right,target,sum,sub);
        sub.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum) {
        // code here
        vector<int> sub;
        fun(root,sum,0,sub);
        return ans;
    }
};
