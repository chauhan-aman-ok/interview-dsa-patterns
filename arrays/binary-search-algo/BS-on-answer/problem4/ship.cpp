// LEETCODE 1011. Capacity To Ship Packages Within D Days
class Solution {
public:
    bool isValid(int maxCap,int days,vector<int> &wt){
         int newDay=1;
         int capacity=0;
         for(auto w:wt){
            if(w>maxCap) return false;
            if(capacity+w<=maxCap) capacity+=w;
            else{
                newDay++;
                capacity=w;
            }
         }
         return newDay<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int beg=*min_element(weights.begin(),weights.end());
        int end=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
    
            if(isValid(mid,days,weights)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};
