// problem 2 - Print subarray with maximum sum (GFG)
// topic - kadanes algortihm


static List<Integer> maxSumSubarray(int[] a) {
       int currSum=a[0];
      int maxSum=a[0];
      int tempStart=0;
      int i=0;
      int j=0;
      for(int k=1;k<a.length;k++){
        if(a[k]>currSum+a[k]){
          currSum=a[k];
          tempStart=k;
        }else{
          currSum+=a[k];
        }
        if(currSum>maxSum){
         maxSum=currSum;
          i=tempStart;
          j=k;
        }
      }
      
        List<Integer> res = new ArrayList<>();
        for (int l = i; l <= j; l++)
            res.add(a[l]);
        return res;
}
