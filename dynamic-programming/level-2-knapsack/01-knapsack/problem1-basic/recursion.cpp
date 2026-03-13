// 0/1 KNAPSACK
//  LINK->  https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// TIME COMPLEXITY : O(2^n) [will throw time limit exceed error] 
// SPACE COMPLEXITY : O(n)

class Solution {
  public:
  
    int recur(vector<int> &val,vector<int> &wt,int idx,int bag){
        if(bag<=0 || idx==wt.size()) return 0;
        if(wt[idx]<=bag){
        int pick=val[idx]+recur(val,wt,idx+1,bag-wt[idx]);
        int skip=recur(val,wt,idx+1,bag);
        return  max(pick,skip);
        }else{
            return recur(val,wt,idx+1,bag);
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        return recur(val,wt,0,W);
    }
};
