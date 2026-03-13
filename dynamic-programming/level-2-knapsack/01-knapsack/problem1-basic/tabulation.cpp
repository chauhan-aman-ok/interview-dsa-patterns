// 0/1 KNAPSACK

// TABULATION for 0/1 Knapsack

//  LINK->  https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// TIME COMPLEXITY : O(n^2) 
// SPACE COMPLEXITY : O(n^2) [dp array]


class Solution {
  public:


    int tabulation(vector<int> &val,vector<int> &wt,int bag,vector<vector<int>> &dp){
        for(int i=0;i<val.size();i++){
            for(int j=1;j<=bag;j++){
                if(i==0){
                    if(wt[i]<=j) dp[i][j]=val[i];
                }
                else{
                    if(wt[i]<=j){
                        dp[i][j]=max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[wt.size()-1][bag];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(),vector<int>(W+1,0));
        return tabulation(val,wt,W,dp);
    }
};

// better function - easy to understand and better as compate to above
int tabulation(vector<int> &val,vector<int> &wt,int bag,vector<vector<int>> &dp){
        for(int i=0;i<=bag;i++){
         if(wt[0]<=i) dp[0][i]=val[0];   
        }
        for(int i=1;i<val.size();i++){
            for(int j=1;j<=bag;j++){
               
                    if(wt[i]<=j){
                        dp[i][j]=max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                
            }
        }
        return dp[wt.size()-1][bag];
}


