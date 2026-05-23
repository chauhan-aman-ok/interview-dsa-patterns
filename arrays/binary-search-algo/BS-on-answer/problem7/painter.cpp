// GFG - The Painter's Partition Problem-II

class Solution {
  public:
    bool isValid(int maxTime,int k,vector<int> &nums){
        int painter=1;
        int time=0;
        for(auto n:nums){
            if(n>maxTime) return false;
            if(n+time<=maxTime){
                time+=n;
            }else{
                painter++;
                time=n;
            }
        }
        return painter<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int beg=*min_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(isValid(mid,k,arr)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};
