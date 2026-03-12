// leetcode 120, triangle
// will give time limit exceed error

// time complexity : O(2^n)
// Space Complexity = O(n)

class Solution {
public:
    int recur(vector<vector<int>> &triangle,int i,int j){
        if(i==triangle.size() || j==triangle[i].size()) return 0 ;
        int down=recur(triangle,i+1,j);
        int downRight=recur(triangle,i+1,j+1);
        return triangle[i][j]+min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        return recur(triangle,0,0);
    }
};
