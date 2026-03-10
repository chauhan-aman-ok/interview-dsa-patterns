// leetocde 64  MINIMUM PATH SUM
// TIME COMPLEXITY - O(2^(m+n))
// SPACE COMPLEXITY - 𝑂(m+n) (due to recursion stack depth)


class Solution {
public:
    int recur(vector<vector<int>> &grid,int i,int j){
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        int right=recur(grid,i,j+1);
        int down=recur(grid,i+1,j);
        return grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return recur(grid,0,0);
    }
};
