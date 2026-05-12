// time complexity - O(n*sum/2)
// space complexity - O(sum/2)
// sum -> sum of the all elements in the array

class Solution {
public:
    bool space(vector<int> &nums,int sum){
        vector<bool> prev(sum+1);
        prev[0]=1;
        if(nums[0]<=sum) prev[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            vector<bool> curr(sum+1);
            for(int j=1;j<=sum;j++){
                int pick=0;
                if(nums[i]<=j){
                  pick=prev[j-nums[i]];
                }
                int skip=prev[j];
                curr[j]=pick||skip;
            }
            prev=curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto n:nums) sum+=n;
        if(sum%2!=0) return false;
        return space(nums,sum/2);
    }
};
