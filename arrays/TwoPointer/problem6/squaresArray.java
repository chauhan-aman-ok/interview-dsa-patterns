// problem 6 : Squares of sorted array, leetcode - 977
// topics - arrays, two pointer

public int[] sortedSquares(int[] a) {
        int i = 0;
        int j = a.length - 1;
        int k = 0;
        int[] res = new int[a.length];
        while (i <= j) {
            int sqi = Math.abs(a[i] * a[i]);
            int sqj = Math.abs(a[j] * a[j]);
            if (i == j) {
                res[k] = sqj;
                break;
            }
            if (sqi < sqj) {
                res[k++] = sqj;
                j--;
            } else {
                res[k++] = sqi;
                i++;
            }
        }
        i = 0;
        while (i < k) {
            int temp = res[i];
            res[i] = res[k];
            res[k] = temp;
            k--;i++;
        }
        return res;
}

