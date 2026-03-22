leetcode 516, Longest Palindromic Subsequence

// PURE RECURSION (will give time limit exceed error)

// TIME COMPLEXITY : O(2^n)
// SPACE COMPLEXITY : O(n)


class Solution {
public:
    int lcs(string &s1,string &s2,int i,int j){
        if(i==s1.size()||j==s2.size()) return 0;
        if(s1[i]==s2[j]){
            return 1+lcs(s1,s2,i+1,j+1);
        }else{
            return max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
        }
    }
    int longestPalindromeSubseq(string s) {
        string st="";
        for(int i=s.size()-1;i>=0;i--) st+=s[i];
        return lcs(s,st,0,0);
    }
};
