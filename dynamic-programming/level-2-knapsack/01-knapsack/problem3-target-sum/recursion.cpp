// LEETCODE 494. Target Sum

// time complexity : O(2^N)
// space complexity : O(n)

//  PURE RECURSION

class Solution {
public:
    int recur(vector<int> &nums,int target,int idx){
        if(idx==nums.size()){
            return (target==0)?1:0;
        }
        int plus=recur(nums,target+nums[idx],idx+1);
        int minus=recur(nums,target-nums[idx],idx+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums,target,0);
    }
};
