// leetcode 518, Coin Change 2

// TABULATION

// Time complexity : O(n × amount)
// Space complexity :  O(n × amount)

class Solution {
public:
   int tabulation(vector<int> &coins,vector<vector<unsigned long long>> &dp,int amt){
       for(int j=0;j<=amt;j++){
        if(j%coins[0]==0) dp[0][j]=1;
       }
       for(int i=1;i<coins.size();i++){
        for(int j=0;j<=amt;j++){
            if(coins[i]<=j){
                dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
            }else dp[i][j]=dp[i-1][j];
        }
       }
       return dp[coins.size()-1][amt];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned long long>> dp(coins.size(),vector<unsigned long long>(amount+1,0));
        return tabulation(coins,dp,amount);
    }

};
