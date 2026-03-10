// leetcode 64. Minimum Path Sum

// TIME COMPLEXITY : O(m*n)
// SPACE COMPLEXITY : O(m*n) [dp array] 

class Solution {
public:
    int tabulation(vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(i==0) dp[i][j]=grid[i][j]+dp[i][j-1];
                if(j==0) dp[i][j]=grid[i][j]+dp[i-1][j];
                if(i>0 && j>0) dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return tabulation(grid);
    }
};

