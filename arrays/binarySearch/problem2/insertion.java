// problem 2 : Search Insert Position
//leetcode : 35
// topic - binary search

class Solution {
    public int searchInsert(int[] nums, int target) {
        return binary(nums,0,nums.length-1,target);
    }
    public int binary(int[] a,int l, int r, int t){
        if(l>r) return l;
        int mid=l+(r-l)/2;
        if(a[mid]==t) return mid;
        if(a[mid]>t) return binary(a,l,mid-1,t);
        else return binary(a,mid+1,r,t);
    }
}


