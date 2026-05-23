// Leetcode 1283. Find the Smallest Divisor Given a Threshold


class Solution {
public:

    bool isValid(int mid,vector<int> &nums,int th){
        int sum=0;
        for(auto n:nums){
            sum+=ceil((double)n/mid);
        }
        return sum<=th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int beg=1,end=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(isValid(mid,nums,threshold)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};
