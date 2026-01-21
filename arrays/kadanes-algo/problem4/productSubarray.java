// leetcode - 152. Maximum Product Subarray
// topic - kadanes algortihm

class Solution {
    public int maxProduct(int[] a) {
     int maxProd=Integer.MIN_VALUE;
     int currMax=1,currMin=1;
     int i=0;
     while(i<a.length){
        int curr=a[i];
        int temp=currMax;
        currMax=Math.max(curr,Math.max(curr*currMax,curr*currMin));
        currMin=Math.min(curr,Math.min(curr*temp,curr*currMin));

        maxProd=Math.max(maxProd,currMax);
        i++;
     }
     return maxProd;
    }
}
