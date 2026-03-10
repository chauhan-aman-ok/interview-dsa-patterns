// leetcode 63. Unique Paths II

// Time Complexity: 𝑂(2𝑚+𝑛)

// Space Complexity: 𝑂(𝑚+𝑛) (due to recursion stack depth)

// will throw time limit exceed error

class Solution {
public:
    int recur(vector<vector<int>> &grid,int i,int j){
        if(i==grid.size() || j==grid[0].size()) return 0;
        if(grid[i][j]==1) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        int right=recur(grid,i,j+1);
        int down=recur(grid,i+1,j);
        return right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        return recur(grid,0,0);
    }
};
