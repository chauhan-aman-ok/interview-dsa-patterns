// leetcode 518, Coin Change 2

// Pure Recursion

// Time complexity : O(n × A) n is the coins array size and A is the amount
// Space complexity :  O(n × A) [DP array space] + O(n + A) [recursion stack] = O(n × A)

class Solution {
public:
    int recur(vector<int> &coins,int amt,int idx,vector<vector<int>> &dp){
        if(amt==0) return 1;
        if(idx==coins.size() || amt<0) return  0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        if(coins[idx]<=amt){
            int pick=recur(coins,amt-coins[idx],idx,dp);
            int skip=recur(coins,amt,idx+1,dp);
            return dp[idx][amt]=pick+skip;
        }else return dp[idx][amt]=recur(coins,amt,idx+1,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return recur(coins,amount,0,dp);
    }
};
