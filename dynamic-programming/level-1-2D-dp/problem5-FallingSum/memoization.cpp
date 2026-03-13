// TIME COMPLEXITY : O(n*m) = O(n^2) since the row and col size is same
// SPACE COMPLEXITY : O(n*m) + O(n) [recursion stack] = O(n*m) = O(n^2)

//Catch in this problem for memoization, if you run memoization with dp filled with -1 then it will give time limit exceed error on a particular test case that contains -1 in grid,
// the memoization acts as normal recursion for that particular test case, 
//so just fill the dp array with -10000 and edit the condition also - if(dp[i][j]!=-10000) in the memoization funtion, then it will be submit.


class Solution {
public:
// recursion+memorization
    int recur(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i==grid.size() || j==grid[0].size()) return 0;
        if(dp[i][j]!=-10000) return dp[i][j];
        if(j==0){
            int down=recur(grid,i+1,j,dp);
            int downRight=recur(grid,i+1,j+1,dp);
            return dp[i][j]= grid[i][j]+min(down,downRight);
        }else if(j==grid[0].size()-1 && j>0){
            int down=recur(grid,i+1,j,dp);
            int downLeft=recur(grid,i+1,j-1,dp);
            return dp[i][j]= grid[i][j]+min(down,downLeft);
        }else{
            int down=recur(grid,i+1,j,dp);
            int downLeft=recur(grid,i+1,j-1,dp);
            int downRight=recur(grid,i+1,j+1,dp);
            return dp[i][j]= grid[i][j]+min(down,min(downRight,downLeft));
        }
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1000));
        int var=INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            var=min(var,recur(grid,0,i,dp));
        }
        return var;
    }
};

