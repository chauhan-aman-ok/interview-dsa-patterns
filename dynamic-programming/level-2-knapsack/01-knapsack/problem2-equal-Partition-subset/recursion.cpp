// LEETCODE 416, Partition Equal Subset Sum

// RECURSION 

// TIME COMPLEXITY : O(2^n) will give time limit exceed error
// SPACE COMPLEXITY : O(n) where n is the size of array nums

class Solution {
public:
    bool recur(vector<int> &nums,int total,int sum,int i){
        if(i==nums.size() || sum>total) return false;
        if(sum==total) return true;
        bool pick=recur(nums,total,nums[i]+sum,i+1);
        bool skip=recur(nums,total,sum,i+1);
        return pick||skip;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto n:nums) total+=n;
        if(total%2!=0) return false;
        return recur(nums,total/2,0,0);
    }
};
