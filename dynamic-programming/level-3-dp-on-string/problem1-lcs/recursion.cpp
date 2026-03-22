leetcode 1143, Longest Common Subsequence

// PURE RECURSION

// TIME COMPLEXITY : O(2^(n+m))
// SPACE COMPLEXITY : O(n + m)

class Solution {
public:
    int lcs(string &s1,string &s2,int i,int j){
        if(i==s1.size() || j==s2.size()) return 0;
        if(s1[i]==s2[j]){
            return 1+lcs(s1,s2,i+1,j+1);
        }
        return max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    }
    int longestCommonSubsequence(string s1, string s2) {
        return lcs(s1,s2,0,0);
    }
};
