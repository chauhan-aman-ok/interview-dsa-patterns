// leetcode 931

// TIME COMPLEXITY : O(n^2)
// SPACE COMPLEXITY : O(n^2) [dp array]

// best among pure recursion and recursion + memoization


class Solution {
public:
    // tabulation
    int tabulation(vector<vector<int>> &grid,vector<vector<int>> &dp){
        for(int i=0;i<grid[0].size();i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(j==0) dp[i][j]=grid[i][j]+min(dp[i-1][j+1],dp[i-1][j]);
                else if(j==grid[0].size()-1) dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                else dp[i][j]=grid[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
            }
        }
        int var=INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            var=min(var,dp[grid.size()-1][i]);
        }
        return var;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
          return tabulation(grid,dp);
    }
};
