// problem 7 : leetcode 238. Product of Array Except Self

here we can compromise the space complexity as the problem mentions that the solution must be finish in O(n) time complexity

java solution -> 


class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] pre=new int[nums.length];
        int[] suf=new int[nums.length];
        pre[0]=nums[0];
        suf[nums.length-1]=nums[nums.length-1];
        for(int i=1;i<nums.length;i++) pre[i]=pre[i-1]*nums[i];
        for(int i=nums.length-2;i>=0;i--) suf[i]=suf[i+1]*nums[i];
        int[] ans=new int[nums.length];
        ans[0]=suf[1];
        ans[nums.length-1]=pre[nums.length-2];
        for(int i=1;i<nums.length-1;i++){
            ans[i]=pre[i-1]*suf[i+1];
        }
        return ans;
    }
}

cpp solution ->

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        vector<int> ans(nums.size());
        pre[0]=nums[0];
        suf[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++) pre[i]=pre[i-1]*nums[i];
        for(int i=nums.size()-2;i>=0;i--) suf[i]=suf[i+1]*nums[i];
        ans[0]=suf[1];
        ans[nums.size()-1]=pre[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++){
            ans[i]=pre[i-1]*suf[i+1];
        }
        return ans;
    }
};




