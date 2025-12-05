// problem 13 - leetcode 1052, grumpy book store owner
// topics - arrays, fixed size sliding window

class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int i = 0;
        int j = 0;
        int currUnsat = 0;
        int maxUnsat = 0;
        int a = 0;
        int b = 0;
        for (int k = 0; k < minutes; k++) {
            if (grumpy[k] == 1)
                currUnsat += customers[k];
        }
        j = minutes - 1;
        while (j < grumpy.length) {
            if (maxUnsat < currUnsat) {
                maxUnsat = currUnsat;
                a = i;
                b = j;
            }
            i++;
            j++;
            if (grumpy[i - 1] == 1)
                currUnsat -= customers[i - 1];
            if (j < customers.length && grumpy[j] == 1)
                currUnsat += customers[j];
        }
        for (int k = a; k <= b; k++)
            if (grumpy[k] == 1)
                grumpy[k] = 0;
        int satisfy = 0;
        for (int k = 0; k < customers.length; k++) {
            if (grumpy[k] == 0)
                satisfy += customers[k];
        }
        return satisfy;
    }
}

