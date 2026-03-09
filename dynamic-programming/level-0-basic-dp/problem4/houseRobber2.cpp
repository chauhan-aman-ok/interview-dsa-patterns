leetcode 213, house robber 2

topic - recursion , dynamic programming

METHOD 1 : RECURSION (will throw time limit exceed)
// time complexity - O(2^n)
// space complexity - O(n)

class Solution {
public:
    int recur(vector<int> &nums,int i,int j){
        if(i>j) return 0;
        int pick=nums[i]+recur(nums,i+2,j);
        int skip=recur(nums,i+1,j);
        return max(pick,skip);
    }
    int rob(vector<int>& nums) {
        return max(recur(nums,0,nums.size()-2),recur(nums,1,nums.size()-1));
    }
};


METHOD 2 : RECURSION + MEMORIZATION
// time complexity - O(n)
// space complexity - O(n) [RECURSION STACK] + O(n) [DP ARRAY] = O(n)
class Solution {
public:
    int recur(vector<int> &nums,int i,int j,vector<int> &dp){
        if(i>j) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+recur(nums,i+2,j,dp);
        int skip=recur(nums,i+1,j,dp);
        return dp[i]= max(pick,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),-1);
        int pick=recur(nums,0,nums.size()-2,dp);
        fill(dp.begin(),dp.end(),-1);
        int skip=recur(nums,1,nums.size()-1,dp);
        return max(pick,skip);
    }
};



METHOD 3 : TABULATION
// time complexity - O(n)
// space complexity - O(n) [DP ARRAY]
class Solution {
public:
    int tabulation(vector<int> &nums,int i,int j,vector<int> dp){
        if(i==j) return nums[i];
        dp[i]=nums[i];
        dp[i+1]=max(nums[i+1],nums[i]);
        for(int k=i+2;k<=j;k++){
            dp[k]=max(dp[k-1],dp[k-2]+nums[k]);
        }
        return dp[j];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),0);
        int pick=tabulation(nums,0,nums.size()-2,dp);
        int skip=tabulation(nums,1,nums.size()-1,dp);
        return max(pick,skip);
    }
};

