// LEETCODE 410. Split Array Largest Sum

class Solution {
public:
    bool isValid(vector<int> &nums,int k, int maxSum){
        int count=1;
        int sum=0;
        for(auto n:nums){
            if(sum+n<=maxSum){
                sum+=n;
            }else{
                count++;
                sum=n;
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int beg=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(isValid(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return ans;
    }
};
