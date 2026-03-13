// LEETCODE 416, Partition Equal Subset Sum

// RECURSION + MEMOIZATION

// TIME COMPLEXITY : O(n*sum)
// SPACE COMPLEXITY : O(n*sum) where n is the size of array nums

// here the implicit type conversion concept is used in dp array of type int storing "true" as "1" and "false" as "0" -> c++ feature

class Solution {
public:
    bool recur(vector<int>& nums, int total, int sum, int i,vector<vector<int>>& dp) {
        if (i == nums.size() || sum > total) return false;
        if (sum == total) return  true;
        if (dp[i][sum] != -1) return dp[i][sum];
        bool pick = recur(nums, total, nums[i] + sum, i + 1, dp);
        bool skip = recur(nums, total, sum, i + 1, dp);
        return dp[i][sum] = pick || skip;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto n : nums) total += n;
        if (total % 2 != 0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>((total / 2)+1 , -1));
        return recur(nums, total / 2, 0, 0, dp);
    }
};
