// problem 12 - Subarray Product Less Than K
// leetcode - 713
// topics - arrays, variable size sliding window

 public int numSubarrayProductLessThanK(int[] a, int k) {
        if(k==0 || k==1) return 0;
        int count=0;
        int prod=1;
        int i=0;
        int j=0;
        while(j<a.length){
            prod*=a[j];
            while(prod>=k && i<=j){
                prod/=a[i++];
            }
            count+=j-i+1;
            j++;
        }
        return count;
 }


