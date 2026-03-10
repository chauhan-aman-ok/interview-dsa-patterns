// leetcode 64. Minimum Path Sum

// TIME COMPLEXITY : O(m*n)
// SPACE COMPLEXITY : O(m*n) [dp array] + O(m+n) [recursion stack] = O(m*n)


class Solution {
public:
    int recur(vector<vector<int>> &grid,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i>=m || j>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return grid[i][j];
        int right=recur(grid,i,j+1,m,n,dp);
        int down=recur(grid,i+1,j,m,n,dp);
        return dp[i][j]= grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recur(grid,0,0,m,n,dp);
    }
};A
