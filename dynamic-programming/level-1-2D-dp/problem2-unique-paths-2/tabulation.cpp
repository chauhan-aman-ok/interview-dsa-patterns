// leetcode 63. Unique Paths II

// TIME COMPLEXITY - O(m*n)

// SPACE COMPLEXITY - O(m*n) [dp array]

class Solution {
public:
   int tabulation(vector<vector<int>> &grid){
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
    dp[0][0]=1;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(i==0 && j==0) continue;
            if(grid[i][j]==1){
                dp[i][j]=0;continue;
            }
            if(i==0) dp[i][j]=dp[i][j-1];
            if(j==0) dp[i][j]=dp[i-1][j];
            if(i>0 && j>0) dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[grid.size()-1][grid[0].size()-1];
   }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]==1 ) return 0;
        return tabulation(grid);
    }
};
