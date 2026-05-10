// space optimized solution for leetcode 62 -


//                      Time Complexity | Space Complexity 
// Tabulation            O(m * n)     |   O(m * n)  
// Space Optimization    O(m * n)     |   O(n)           |



class Solution {
public:
    int space(int m,int n){
        vector<int> prev(n);
        prev[0]=1;
        for(int i=0;i<m;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
              if(i==0 && j==0) {
                curr[0]=prev[0];
                continue;}
              if(i==0) curr[j]+=curr[j-1];
              if(j==0) curr[j]+=prev[j];
              if(i>0 && j>0) curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        return space(m,n);
    }
};
