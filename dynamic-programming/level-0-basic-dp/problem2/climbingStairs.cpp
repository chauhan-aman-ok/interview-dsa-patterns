// METHOD 1 : RECURSION 
// T.C. - O(2^n)
// S.C. - O(n) -> recursion stack

class Solution {
public:
    int recur(vector<int> &cost,int idx){
        if(idx>=cost.size()) return 0;
        return cost[idx]+min(recur(cost,idx+1),recur(cost,idx+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(recur(cost,0),recur(cost,1));
    }
};

// METHOD 2 : RECURSION + MEMORIZATION
// T.C. - O(n)
// S.C. - O(n)+O(n) = O(n) -> recursion stack + dp array
class Solution {
public:
    int recur(vector<int> &cost,int idx,vector<int> &dp){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]= cost[idx]+min(recur(cost,idx+1,dp),recur(cost,idx+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(recur(cost,0,dp),recur(cost,1,dp));
    }
};


// METHOD 3 : TABULATION (ITERATIVE)
// T.C. - O(n)
// S.C. - O(n) -> dp array

class Solution {
public:
    int tabulation(vector<int> &cost,vector<int> &dp){
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[cost.size()-2],dp[cost.size()-1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return tabulation(cost,dp);
    }
};

