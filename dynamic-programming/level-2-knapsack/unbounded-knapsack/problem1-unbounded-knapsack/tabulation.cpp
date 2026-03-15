// UNBOUNDED KNAPSACK

// LINK - https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// TABULATION


// TIME COMPLEXITY - O(n*bag)
// SPACE COMPLEXITY -O(n*bag)

class Solution {
  public:
int tabulation(vector<int> &val,vector<int>& wt,int bag,vector<vector<int>> &dp){
     for(int j = 0; j <= bag; j++) {
            dp[0][j] = (j / wt[0]) * val[0];
        }

    for(int i=1;i<wt.size();i++){
        for(int j=1;j<=bag;j++){
            
            if(j<wt[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],val[i]+dp[i][j-wt[i]]);
            }
            
        }
    }
    return dp[wt.size()-1][bag];
}
    int knapSack(vector<int>& val, vector<int>& wt, int bag) {
        // code here
        vector<vector<int>> dp(val.size(),vector<int>(bag+1,0));
        return tabulation(val,wt,bag,dp);
    }
};
