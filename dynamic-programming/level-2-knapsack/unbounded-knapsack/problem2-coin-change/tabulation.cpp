leetcode 322, Coin change 

// TABULATION

// TIME COMPLEXITY : O(n×A) 
// SPACE COMPLEXITY : O(n×A)

class Solution {
public:
    
int tabulation(vector<int> &coins,int amount,vector<vector<long>> &dp){
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) dp[0][j] = j / coins[0];
            else dp[0][j] = INT_MAX;  
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(j<coins[i]) dp[i][j]= dp[i-1][j];
                else {
                    dp[i][j]=min(1+dp[i][j-coins[i]],dp[i-1][j]);
                }
            }
        }
        return dp[coins.size()-1][amount] >= INT_MAX ? -1 : dp[coins.size()-1][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<long>> dp(coins.size(),vector<long>(amount+1,INT_MAX));
        return tabulation(coins,amount,dp);
    }
};
