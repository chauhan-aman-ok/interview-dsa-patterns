leetcode 322, Coin change 

// PURE RECURSION

// TIME COMPLEXITY : O(2^a) a is the amount [will give time limit exceed error]
// SPACE COMPLEXITY : O(a+n) = O(a) a is the amount



class Solution {
public:
    long recur(vector<int> &coin,int amount,int idx){
    if(amount==0) return 0;
    if(amount<0 || idx==coin.size()) return INT_MAX;
        if(coin[idx]<=amount){
            long pick=1+recur(coin,amount-coin[idx],idx);
            long skip=recur(coin,amount,idx+1);
            return min(pick,skip);
        }else return recur(coin,amount,idx+1);
    }
    int coinChange(vector<int>& coins, int amount) {
        long res= recur(coins,amount,0);
        return (res>=INT_MAX)?-1:res;
    }
};
