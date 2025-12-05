//problem 11 -  Longest Subarray of 1's After Deleting One Element
// leetcode - 1493
// topics - arrays, variable size sliding window
 
class Solution {
    public int longestSubarray(int[] a) {
        int i = 0;
        int j = 0;
        int zCount = 0;
        int len = 0;
        int z=0; // for a particular  case no. 3 -> 1,1,1
        for(int ele : a){
            if(ele==0) z++;
        }
        if(z==0) return a.length-1;
        // 
        while (i < a.length && a[i] == 0) {
            i++;
        }
        j = i;
        while (j < a.length) {
            if (a[j] == 0) {
                if (zCount == 0) {
                    zCount++;
                    j++;
                } else {
                    len = Math.max(len, j - i - 1);
                    j++;
                    while (i < a.length && a[i] != 0)
                        i++;
                    i++;
                }
            } else {
                j++;
            }
        }
        if (zCount == 0)
            return j - i;
        return Math.max(len, j - i - 1);// for particular case [1,1,0,1] -> Math.max(len, j - i - 1), else we can just write -> return len
    }
}
