package arrays.slidingwindow;
// problem1 - find the maximum possible sum of any contiguous subarray of size k.
// topic - fixed-size sliding window
public class subarraySum {
    public static int subarraySum(int[] nums, int k) {
        int currSum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            currSum+=nums[i];
        }
        int i=1;
        int j=k;
        while(j<nums.length){
            maxSum=Math.max(maxSum,currSum+nums[j]);
            currSum=currSum-nums[i-1]+nums[j];
            i++;
            j++;
        }
        return maxSum;
    }
    public static void main(String[] args) {
        int[] a={1,0,0,1,2,3,0,1,1,0};
        System.out.println(subarraySum(a,3));
    }
}
