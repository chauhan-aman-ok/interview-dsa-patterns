// leetcode 198 HOUSE ROBBER

// topic recursion, dynamic programming

METHOD 1 : RECURSION (will throw time limit exceed)
// time complexity - O(2^n)
// space complexity - O(n)

int recur(vector<int> &nums,int idx){
        if(idx>=nums.size()) return 0;
        int pick= nums[idx]+recur(nums,idx+2);
        int skip=recur(nums,idx+1);
        return max(pick,skip);
}
int rob(vector<int>& nums) {
        return max(recur(nums,0),recur(nums,1));
}


METHOD 2 : RECURSION + MEMORIZATION
// time complexity - O(n)
// space complexity - O(n) [recursion stack] + O(n) [dp array] = O(n)
int memo(vector<int> &nums,int idx,vector<int> &dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+memo(nums,idx+2,dp);
        int skip=memo(nums,idx+1,dp);
        return dp[idx]=max(pick,skip);
}
int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return max(memo(nums,0,dp),memo(nums,1,dp));
}


METHOD 3 : TABULATION
// time complexity - O(n)
// space complexity - O(n)

int tabulation(vector<int> &nums,vector<int> &dp){
        if(nums.size()<=1) return nums[nums.size()-1];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
}
int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return tabulation(nums,dp);
}


