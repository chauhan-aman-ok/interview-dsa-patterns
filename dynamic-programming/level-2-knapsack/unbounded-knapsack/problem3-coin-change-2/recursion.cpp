leetcode 518, Coin Change 2

// Pure Recursion

// Time complexity : O(2^A)
// Space complexity : O(A+n) = O(A) where 'A' is the amount

class Solution {
public:
    int recur(vector<int> &coins,int amt,int idx){
        if(amt==0) return 1;
        if(idx==coins.size() || amt<0) return 0;
        if(coins[idx]<=amt){
            int pick=recur(coins,amt-coins[idx],idx);
            int skip=recur(coins,amt,idx+1);
            return pick+skip;
        }else return recur(coins,amt,idx+1);
    }
    int change(int amount, vector<int>& coins) {
        return recur(coins,amount,0);
    }
};
