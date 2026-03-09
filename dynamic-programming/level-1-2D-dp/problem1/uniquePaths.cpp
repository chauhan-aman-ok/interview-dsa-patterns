leetcode 62 unique paths
// topic - recursion , dynamic programming


METHOD 1 : RECURSION
//Time Complexity: O(2^(m+n))
//Space Complexity: O(m + n)
class Solution {
public:
    int recur(int m,int n,int i,int j){
        if(i==m-1 || j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        return  recur(m,n,i+1,j)+recur(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        return recur(m,n,0,0);
    }
};

METHOD 2 : RECURSION + MEMORIZATION
// TIME COMPLEXITY : O(m*n)
// Space Complexity: O(m × n) 
//O(m × n) for DP table
//O(m + n) recursion stack 

class Solution {
public:
    int recur(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1 || j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]= recur(m,n,i+1,j,dp)+recur(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recur(m,n,0,0,dp);
    }
};


METHOD 3 : TABULATION
// TIME COMPLEXITY : O(m*n)
// SPACE COMPLEXITY : O(m*n)
class Solution {
public:
    int tabulation(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    dp[0][0]=1;
                    continue;
                    }
                if(i==0) dp[i][j]=dp[i][j-1];
                if(j==0) dp[i][j]=dp[i-1][j];
                if(i>0 && j>0) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        return tabulation(m,n);
    }
};
