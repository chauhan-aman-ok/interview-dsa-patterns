// problem 5 : Leetcode 69. Sqrt(x)
// topic binary search


class Solution {
    public int mySqrt(int x) {
        int beg=0,end=x;
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if((long)mid*mid==x) return mid;
            if((long)mid*mid<x){
                beg=mid+1;
                ans=mid;
            }
            else end=mid-1;
        }
        return ans;
    }
}
