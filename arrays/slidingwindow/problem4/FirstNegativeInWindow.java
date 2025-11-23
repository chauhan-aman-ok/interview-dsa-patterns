// problem 4 - First Negative Number in Every Window of Size K, available on gfg
// topics - fixed size sliding window + queue
// we can use normal queue also here



import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class FirstNegativeInWindow {
    public static List<Integer> firstNegInt(int arr[], int k){

        List<Integer> res = new ArrayList<>();
        Deque<Integer> q = new ArrayDeque<>();
        int n = arr.length;

        if (k > n) return res;

        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                q.add(i);
            }
        }

        if (q.isEmpty()) res.add(0);
        else res.add(arr[q.peek()]);

        for (int i = k; i < n; i++) {

            while (!q.isEmpty() && q.peek() <= i - k) {
                q.poll();
            }

            if (arr[i] < 0) {
                q.add(i);
            }

            if (q.isEmpty()) res.add(0);
            else res.add(arr[q.peek()]);
        }

        return res;
    }
}
