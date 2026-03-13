// LEETCODE 931, MIN. FALLING PATH SUM

// TIME COMPLEXITY : O(n × 3ⁿ)
// SPACE COMPLEXITY : O(n)
class Solution {
public:
 // recursion only
 int recurs(vector<vector<int>> &grid,int i,int j){
        if(i==grid.size() || j==grid[0].size()) return 0;
        if(j==0){
            int down=recurs(grid,i+1,j);
            int downRight=recurs(grid,i+1,j+1);
            return grid[i][j]+min(down,downRight);
        }else if(j==grid[0].size()-1 && j>0){
            int down=recurs(grid,i+1,j);
            int downLeft=recurs(grid,i+1,j-1);
            return grid[i][j]+min(down,downLeft);
        }else{
            int down=recurs(grid,i+1,j);
            int downLeft=recurs(grid,i+1,j-1);
            int downRight=recurs(grid,i+1,j+1);
            return grid[i][j]+min(down,min(downRight,downLeft));
        }
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int var=INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            var=min(var,recur(grid,0,i));
        }
        return var;
    }
};
