// GFG - Allocate Minimum Pages

class Solution {
  public:
    bool isValid(int pages,int k,vector<int> &nums){
        int student=1;
        int pageCount=0;
        for(auto n:nums){
            if(n+pageCount<=pages){
                pageCount+=n;
            }else{
                student++;
                pageCount=n;
            }
        }
        return student<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int ans=-1;
        if(arr.size()<k) return ans;
        
        int beg=*max_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
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
