leetcode 516, Longest Palindromic Subsequence

// TABULATION (ITERATIVE)

// TIME COMPLEXITY : O(n²)
// SPACE COMPLEXITY : O(n²)

class Solution {
public:
    int lcs(string &s1,string &s2,vector<vector<int>> &dp){
        if(s1[0]==s2[0]) dp[0][0]=1;
        for(int i=1;i<s1.size();i++){
            if(s1[i]==s2[0]) dp[i][0]=1;
            else dp[i][0]=dp[i-1][0];
        }
        for(int j=1;j<s2.size();j++){
            if(s1[0]==s2[j]) dp[0][j]=1;
            else dp[0][j]=dp[0][j-1];
        }
        for(int i=1;i<s1.size();i++){
            for(int j=1;j<s2.size();j++){
                if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s1.size()-1][s2.size()-1];
    }
    int longestPalindromeSubseq(string s) {
        string st="";
        for(int i=s.size()-1;i>=0;i--) st+=s[i];
        vector<vector<int>> dp(s.size(),vector<int>(st.size(),0));
        return lcs(s,st,dp);
    }
};
