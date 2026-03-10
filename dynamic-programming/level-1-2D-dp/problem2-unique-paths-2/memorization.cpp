// leetcode 63. Unique Paths II

// RECURSION + MEMORIZATION

// TIME COMPLEXITY - O(m*n)
// SPACE COMPLEXITY - O(m*n) [dp array] + O(m+n) [recursion stack] = O(m*n)


class Solution {
public:
    int recur(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i==grid.size() || j==grid[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        int right=recur(grid,i,j+1,dp);
        int down=recur(grid,i+1,j,dp);
        return dp[i][j]= right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return recur(grid,0,0,dp);
    }
};
