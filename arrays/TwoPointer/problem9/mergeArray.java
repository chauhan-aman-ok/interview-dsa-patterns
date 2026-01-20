// leetcode - 88 merge sorted arrray
// topic - three pointer
class Solution {
    public void merge(int[] a1, int m, int[] a2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(a1[i]>a2[j]){
                a1[k--]=a1[i--];
            }else{
                a1[k--]=a2[j--];
            }
        }
        while(j>=0)  a1[k--]=a2[j--];
    }
}

