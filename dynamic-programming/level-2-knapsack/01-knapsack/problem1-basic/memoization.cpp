// 0/1 KNAPSACK

// recursion + memoization

//  LINK->  https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// TIME COMPLEXITY : O(n*W) [will throw time limit exceed error] 
// SPACE COMPLEXITY : O(n) [recursion stack] + O(n*W) [dp array] = O(n*W)

class Solution {
  public:
    int memo(vector<int> &val,vector<int> &wt,int idx,int bag,vector<vector<int>> &dp){
        if(bag<=0 || idx==wt.size()) return 0;
        if(dp[idx][bag]!=-1) return dp[idx][bag];
        if(wt[idx]<=bag){
        int pick=val[idx]+memo(val,wt,idx+1,bag-wt[idx],dp);
        int skip=memo(val,wt,idx+1,bag,dp);
        return dp[idx][bag]= max(pick,skip);
        }else{
            return dp[idx][bag]= memo(val,wt,idx+1,bag,dp);
        }
    }
   
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(val.size(),vector<int>(W+1,-1));
        return memo(val,wt,0,W,dp);
    }
};
