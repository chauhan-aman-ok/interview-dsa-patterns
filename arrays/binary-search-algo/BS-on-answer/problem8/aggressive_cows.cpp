// GFG - Aggressive Cows
class Solution {
  public:
  
    bool isValid(int minDist, int k, vector<int> &stalls) {
        
        int cows = 1;
        int lastPlaced = stalls[0];
       
        for(int i = 1; i < stalls.size(); i++) {
      
            if(stalls[i] - lastPlaced >= minDist) {
                cows++;
                lastPlaced = stalls[i];
            }
        }
        
        return cows >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int beg=1;
        int end=stalls.back()-stalls[0];
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(isValid(mid,k,stalls)){
                ans=mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};
