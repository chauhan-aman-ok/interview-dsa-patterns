// space complexity - O(n)
// time complexity - O(n*capacity)


class Solution {
  public:
     int tabulation(vector<int> &val,vector<int> &wt,int bag){
         vector<int> prev(bag+1);
     
         for(int j=0;j<=bag;j++) prev[j]=(j/wt[0])*val[0];
         
         for(int i=1;i<val.size();i++){
             vector<int> curr(bag+1);
             for(int j=1;j<=bag;j++){
                 if(j<wt[i]) curr[j]=prev[j];
                 else {
                     curr[j]=max(prev[j],val[i]+curr[j-wt[i]]);
                 }
             }
             prev=curr;
         }
         return prev[bag];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        return tabulation(val,wt,capacity);
    }
};

