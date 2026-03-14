// UNBOUNDED KNAPSACK

// LINK - https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// PURE RECURSION 


// TIME COMPLEXITY - O(2^(n + bag))
// SPACE COMPLEXITY - O(n + bag)


class Solution {
  public:
int unbound(vector<int> &val,vector<int>& wt,int bag,int idx){
    if(idx==val.size() || bag<=0) return 0;
    if(wt[idx]<=bag){
        int pick=val[idx]+unbound(val,wt,bag-wt[idx],idx,dp);
        int skip=unbound(val,wt,bag,idx+1,dp);
        return max(pick,skip);
    }else return unbound(val,wt,bag,idx+1,dp);
}
    int knapSack(vector<int>& val, vector<int>& wt, int bag) {
        // code here
        return unbound(val,wt,bag,0);
    }
};
