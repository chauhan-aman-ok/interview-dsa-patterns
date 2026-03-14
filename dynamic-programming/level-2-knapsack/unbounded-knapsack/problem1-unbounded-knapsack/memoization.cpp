// UNBOUNDED KNAPSACK

// LINK - https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// RECURSION + MEMOIZATION


// TIME COMPLEXITY - O(n*bag)
// SPACE COMPLEXITY -O(n*bag)+O(n+bag) = O(n*bag)


class Solution {
  public:
int unbound(vector<int> &val,vector<int>& wt,int bag,int idx,vector<vector<int>> &dp){
    if(idx==val.size() || bag<=0) return 0;
    if(dp[idx][bag]!=-1) return dp[idx][bag];
    if(wt[idx]<=bag){
        int pick=val[idx]+unbound(val,wt,bag-wt[idx],idx,dp);
        int skip=unbound(val,wt,bag,idx+1,dp);
        return dp[idx][bag]= max(pick,skip);
    }else return dp[idx][bag]= unbound(val,wt,bag,idx+1,dp);
}
    int knapSack(vector<int>& val, vector<int>& wt, int bag) {
        // code here
        vector<vector<int>> dp(val.size(),vector<int>(bag+1,-1));
        return unbound(val,wt,bag,0,dp);
    }
};
