// problem - 6 : leetcode 724, Pivot Index

java solution ->

class Solution {
    public int pivotIndex(int[] nums) {
        int[] pre=new int[nums.length];
        int[] suf=new int[nums.length];
        pre[0]=nums[0];
        suf[nums.length-1]=nums[nums.length-1];
        for(int i=1;i<nums.length;i++) pre[i]=pre[i-1]+nums[i];
        for(int i=nums.length-2;i>=0;i--) suf[i]=suf[i+1]+nums[i];
        for(int i=0;i<nums.length;i++){
            if(pre[i]-suf[i]==0) return i;
        }
        return -1;
    }
}


cpp solution ->

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        pre[0]=nums[0];
        suf[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++) pre[i]=pre[i-1]+nums[i];
        for(int i=nums.size()-2;i>=0;i--) suf[i]=suf[i+1]+nums[i];
        for(int i=0;i<nums.size();i++){
            if(pre[i]-suf[i]==0) return i;
        }
        return -1;
    }
};

hence, the above solutions have T.C. = O(n) but Space Complexity = 2*n because we are creating 2 extra arrays named pre and suf,
 so technically its O(2n) but we ignores the constant in the time and space complexity so the final space complexity is O(n) 


