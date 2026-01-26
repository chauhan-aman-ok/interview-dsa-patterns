// problem 2 : leetcode 303. Range Sum Query - Immutable
// topic - prefix sum

class NumArray {
    int[] pre;
    public NumArray(int[] nums) {
        pre=new int[nums.length];
        pre[0]=nums[0]; 
        for(int i=1;i<nums.length;i++){
            pre[i]=nums[i]+pre[i-1];
        }
    }
    
    public int sumRange(int left, int right) {
        if(left==0) return pre[right];
        return pre[right]-pre[left-1];
    }
}

