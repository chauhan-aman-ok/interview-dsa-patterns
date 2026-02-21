// leetcode - 108. Convert Sorted Array to Binary Search Tree


class Solution {
public:
    TreeNode* helper(vector<int> &nums,int low,int high){
        if(low>high) return nullptr;
        int mid=low+(high-low)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,low,mid-1);
        root->right=helper(nums,mid+1,high);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};


// can also be optimized for space complexity, pattern - RANGE PATTERN
