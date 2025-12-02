// Problem 9 - Leetcode 1004. Max Consecutive Ones III
// topics - variable size sliding windnow, arrays


class Solution {
    public int longestOnes(int[] nums, int k) {
       int i=0;
       int maxLen=0;
       int zeroCount=0;
       for(int j=0;j<nums.length;j++){
        if(nums[j]==0) zeroCount++;
        while(zeroCount>k){
         if(nums[i]==0)   zeroCount--;
           i++;
        }
         maxLen = Math.max(maxLen, j - i + 1);
       }
       return maxLen;
    }
}
