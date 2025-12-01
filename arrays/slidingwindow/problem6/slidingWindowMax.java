//problem - Leetcode 239, Sliding Window Max
//topics- queue, fixed sliding window

 public int[] maxSlidingWindow(int[] a, int k) {
        int n = a.length;
        int[] res = new int[n - k + 1];  
        int resIndex = 0;

        Deque<Integer> q = new ArrayDeque<>();

        for (int i = 0; i < k; i++) {

            while (!q.isEmpty() && a[q.peekLast()] <= a[i]) {
                q.pollLast();
            }
            q.addLast(i);
        }
        int i = 1;
        int j = k;

        while (j < n) {

            res[resIndex++] = a[q.peekFirst()];

            while (!q.isEmpty() && q.peekFirst() < i) {
                q.pollFirst();
            }

            while (!q.isEmpty() && a[q.peekLast()] <= a[j]) {
                q.pollLast();
            }
            q.addLast(j);

            i++;
            j++;
        }

        res[resIndex] = a[q.peekFirst()];

        return res;
 }
