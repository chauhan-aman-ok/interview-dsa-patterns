// TABULATION (iterative only, no recursion)

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
public:
    int tabulation(vector<vector<int>> &triangle,vector<vector<int>> &dp){
        dp[0][0]=triangle[0][0];
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i==0 && j==0) continue;
                if(j==0) dp[i][j]=triangle[i][j]+dp[i-1][j];
                else if(j==triangle[i].size()-1) dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                else dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<dp[dp.size()-1].size();i++){
            ans=min(ans,dp[dp.size()-1][i]);
        }
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        for(int i=0;i<triangle.size();i++) dp[i]=vector<int>(triangle[i].size(),INT_MAX);
        return tabulation(triangle,dp);
    }
};
