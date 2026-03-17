leetcode 322, Coin change 

//  RECURSION + MEMOIZAITON

// TIME COMPLEXITY : O(n×A) 'A' is the amount and 'n' is the size of coin array
// SPACE COMPLEXITY : O(n×A)+O(A) [recursion stack] = O(nxA)

class Solution {
public:
    long recur(vector<int> &coin,int amount,int idx,vector<vector<long>> &dp){
    if(amount==0) return 0;
    if(amount<0 || idx==coin.size()) return INT_MAX;
    if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(coin[idx]<=amount){
            long pick=1+recur(coin,amount-coin[idx],idx,dp);
            long skip=recur(coin,amount,idx+1,dp);
            return dp[idx][amount]= min(pick,skip);
        }else return dp[idx][amount]= recur(coin,amount,idx+1,dp);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<long>> dp(coins.size(),vector<long>(amount+1,-1));
        long res= recur(coins,amount,0,dp);
        return (res>=INT_MAX)?-1:res;
    }
};
