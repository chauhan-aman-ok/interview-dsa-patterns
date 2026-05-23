// LEETCODE 875. Koko Eating Bananas

class Solution {
public:
    bool isValid(int mid,int hours,vector<int> &piles){
        int count=0;
        for(auto p:piles){
           if(p<=mid) count++;
           else{
                count+=p/mid;
               if(p%mid!=0) count++;
           }

           if(count>hours) return false;
        }
      return count<=hours?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int beg=1,end=*max_element(piles.begin(),piles.end());
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(isValid(mid,h,piles)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};
