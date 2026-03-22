leetcode 516, Longest Palindromic Subsequence

//  RECURSION + MEMOIZATION

// TIME COMPLEXITY : O(n²)
// SPACE COMPLEXITY : O(n²)[dp array] + O(n)[recursion stack] + O(n) [string] = O(n²)

class Solution {
public:
    int lcs(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i==s1.size()||j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+lcs(s1,s2,i+1,j+1,dp);
        }else{
            return dp[i][j]= max(lcs(s1,s2,i+1,j,dp),lcs(s1,s2,i,j+1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string st="";
        for(int i=s.size()-1;i>=0;i--) st+=s[i];
        vector<vector<int>> dp(s.size(),vector<int>(st.size(),-1));
        return lcs(s,st,0,0,dp);
    }
};
