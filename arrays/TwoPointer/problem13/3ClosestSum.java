// leetcode - 16
// 3 Closest Sum
// topics - 3 pointer

class Solution {
    public int threeSumClosest(int[] a, int t) {
        int i=0;
        Arrays.sort(a);
        int closeSum=a[0]+a[1]+a[2];
        while(i<a.length-1){
           int j=i+1,k=a.length-1;
           while(j<k){
            int sum=a[i]+a[j]+a[k];
            if(Math.abs(sum-t)<Math.abs(closeSum-t)){
              closeSum=sum;
            }else if(sum<t){
                j++;
            }else if(sum>t){
                k--;
            }else{
                return closeSum;
            }
           }
           i++;
        }
        return closeSum;
    }
}


