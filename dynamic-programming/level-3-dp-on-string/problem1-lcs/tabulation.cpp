leetcode 1143, Longest Common Subsequence

// TABULATION (ITERATIVE)

// TIME COMPLEXITY : O(n * m)
// SPACE COMPLEXITY : O(n*m)

class Solution {
public:
    int tabulation(string s1,string s2,vector<vector<int>> &dp){
        if(s1[0]==s2[0]) dp[0][0]=1;
        for(int j=1;j<s2.size();j++){
            if(s1[0]==s2[j]) dp[0][j]=1;
            else dp[0][j]=dp[0][j-1];
        }
        
        for(int i=1;i<s1.size();i++){
         if(s1[i]==s2[0]) dp[i][0]=1;   
          else dp[i][0]=dp[i-1][0];
        }
        
        for(int i=1;i<s1.size();i++){
            for(int j=1;j<s2.size();j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1.size()-1][s2.size()-1];
    }
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),0));
        return tabulation(s1,s2,dp);
    }
};
