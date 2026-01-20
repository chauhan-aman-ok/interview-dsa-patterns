// problem 2 - Print subarray with maximum sum (GFG)
// topic - kadanes algortihm


 static List<Integer> maxSumSubarray(int[] a) {
        
        
      int currSum=0;
      int maxSum=Integer.MIN_VALUE;
      int i=0,j=0;
      int tempStart=0;
        for (int k = 0; k < a.length; k++) {
            currSum+=a[k];
          if(currSum>maxSum){
          maxSum=currSum;
            i=tempStart;
            j=k;
          }
          if(currSum<0){
          currSum=0;
            tempStart=k+1;
          }
        }
      
        List<Integer> res = new ArrayList<>();
        for (int k = i; k <= j; k++)
            res.add(a[k]);
        return res;
 }
