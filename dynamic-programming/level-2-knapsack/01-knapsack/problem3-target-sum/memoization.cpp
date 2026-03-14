// LEETCODE 494. Target Sum

// time complexity : O(n*sum)
// space complexity : O(n*sum)

// RECURSION + MEMOIZATION


class Solution {
public:
    int recur(vector<int> &nums,int target,int idx,vector<vector<int>> &dp,int sum){
        if(target > sum || target < -sum) return 0;
        if(idx==nums.size()){
            return (target==0)?1:0;
        }
        if(dp[idx][target+sum]!=-1) return dp[idx][target+sum];
//Without shift:
//-5 -4 -3 -2 -1 0 1 2 3 4 5 here dp[idx][-5] is not possible so it will become dp[idx][-5+target]=dp[idx][0]
//Array cannot start at -5.
//After shift:
//0 1 2 3 4 5 6 7 8 9 10
        int plus=recur(nums,target+nums[idx],idx+1,dp,sum);
        int minus=recur(nums,target-nums[idx],idx+1,dp,sum);

        return dp[idx][target+sum]= plus+minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto ele:nums) sum+=ele;
//         Suppose:  
//         nums = [1,2,3] sum = 6 target = 10
//         Then first call: dp[idx][10+6]
//         which is: dp[idx][16]
//         But dp size: 13
        if(abs(target) > sum) return 0;

        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,-1));
        return recur(nums,target,0,dp,sum);
    }
};


