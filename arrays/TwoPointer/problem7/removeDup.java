// leetcode - 26
// Remove Duplicates from Sorted Array
// topics- slow fast two pointer
class Solution {
    public int removeDuplicates(int[] a) {
        int i=0, j=1;
        while(j<a.length){
           if(a[i]!=a[j]){
            a[++i]=a[j];
           }else{
            j++;
           }
        }
        return i+1;
    }
}

