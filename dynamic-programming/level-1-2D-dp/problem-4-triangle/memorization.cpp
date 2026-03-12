// Time Complexity : O(n^2)
// Space Complexity : O(n^2)(DP table)+O(n)(recursion stack)
//  RECURSION + MEMORIZATION
class Solution {
public:
    int recur(vector<vector<int>> &triangle,int i,int j,vector<vector<int>> &dp){
        if(i==triangle.size() || j==triangle[i].size()) return 0 ;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int down=recur(triangle,i+1,j,dp);
        int downRight=recur(triangle,i+1,j+1,dp);
        return dp[i][j]=triangle[i][j]+min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        for(int i=0;i<triangle.size();i++) dp[i]=vector<int>(triangle[i].size(),INT_MAX);
        return recur(triangle,0,0,dp);
    }
};
