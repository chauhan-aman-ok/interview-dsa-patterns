// LEETCODE 416, Partition Equal Subset Sum

// TABULATION

// TIME COMPLEXITY : O(n*sum)
// SPACE COMPLEXITY : O(n*sum) where n is the size of array nums

class Solution {
public:
    bool tabulation(vector<int> &nums,int subSum,vector<vector<bool>> &dp){
        for(int i=0;i<nums.size();i++) dp[i][0]=true;
        if(nums[0]<=subSum) dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=subSum;j++){
                int pick=false;
                if(nums[i]<=j) pick=dp[i-1][j-nums[i]];
                int skip=dp[i-1][j];
                dp[i][j]=pick||skip;
            }
        }
        return dp[nums.size()-1][subSum];
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto a:nums) total+=a;
        if(total%2!=0) return false;
        int subSum=total/2;
        vector<vector<bool>> dp(nums.size(),vector<bool>(subSum+1,false));
        return tabulation(nums,subSum,dp);
    }
};
