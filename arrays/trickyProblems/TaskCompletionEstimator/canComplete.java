/*
 ------------------------------------------------------------
  Problem: Task Completion Estimator for Multi-Stage Software Teams
 ------------------------------------------------------------

 Liam manages a software engineering team responsible for completing N tasks
 before the upcoming product release. Each task must sequentially pass through
 the following three stages:

   1. Feature Development
   2. Bug Fixing
   3. Code Review

 The team consists of three groups of developers:
   - n1 developers for Feature Development
   - n2 developers for Bug Fixing
   - n3 developers for Code Review

 All developers within the same group work with equal efficiency.

 ------------------------------------------------------------
  Work Distribution Logic
 ------------------------------------------------------------

 Each stage must process ALL N tasks. A new stage begins ONLY after the
 previous stage finishes all tasks.

 Developers in the same stage work IN PARALLEL and divide the tasks among
 themselves.

 Time taken per task at each stage:
   - Feature Development: d days per task
   - Bug Fixing: (d + 2) days per task
   - Code Review: (d - 2) days per task



 ------------------------------------------------------------
  Output Format
 ------------------------------------------------------------

 If the tasks can be completed within the available days D:
      Yes X
 Where X is the total required days.

 Otherwise:
      No Y
 Where Y is the number of extra days needed.



 Input:
    N = 5
    n1 = 3
    n2 = 3
    n3 = 9
    d = 6
    D = 30

 Output:
    Yes 26

*/
public class TaskCompletionEstimator {

    public static String canComplete(int N, int n1, int n2, int n3, int d, int D) {

        double t1 = ((double) N / n1) * d;
        double t2 = ((double) N / n2) * (d + 2);
        double t3 = ((double) N / n3) * (d - 2);

        double totalTime = t1 + t2 + t3;

        int requiredDays = (int) Math.ceil(totalTime);
        if (requiredDays <= D) {
            return "Yes " + requiredDays;
        } else {
            return "No " + (requiredDays - D);
        }
    }

    public static void main(String[] args) {
        System.out.println(canComplete(5, 3, 3, 9, 6, 30));    }
}

