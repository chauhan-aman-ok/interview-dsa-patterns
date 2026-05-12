// space complexity - O(n)
// time complexity - O(n*amount)


class Solution {
public:
    long tabulation(vector<int> &coins,int amt){
        vector<long> prev(amt+1);
        for(int j=0;j<=amt;j++){
            if(j%coins[0]==0) prev[j]=(j/coins[0]);
            else prev[j]=INT_MAX;
        }
        for(int i=1;i<coins.size();i++){
              vector<long> curr(amt+1);
                for(int j=0;j<=amt;j++){
                    if(j<coins[i]) curr[j]=prev[j];
                    else curr[j]=min(prev[j],1+curr[j-coins[i]]);
                }
                prev=curr;
            }
            return prev[amt];
    }

    int coinChange(vector<int>& coins, int amount) {
        long ans=tabulation(coins,amount);
        return (ans>=INT_MAX)?-1:ans;
    }
};

