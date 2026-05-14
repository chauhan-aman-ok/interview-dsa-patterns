// space complexity - O(n)
// time complexity - O(n*amount)


class Solution {
public:
    int tabulation(int amount,vector<int> &coins){
        vector<unsigned long long> prev(amount+1);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=1;
        }
        for(int i=1;i<coins.size();i++){
            vector<unsigned long long> curr(amount+1);
            for(int j=0;j<=amount;j++){
                if(j<coins[i]) curr[j]=prev[j];
                else{
                    curr[j]=prev[j]+curr[j-coins[i]];
                }
            }
            prev=curr;
        }
        return prev[amount];

    }
    int change(int amount, vector<int>& coins) {
        return tabulation(amount,coins);
    }
};

