// space complexity - 2n -> O(n)
// time complexity - O(m*n)

class Solution {
public:
    
    int space(vector<vector<int>>& grid,int m,int n){
        vector<int> prev(n);
        prev[0]=1;
        for(int i=0;i<m;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=prev[j];
                     continue;}
                if(grid[i][j]==1) curr[j]=0;
                else if(i==0) curr[j]+=curr[j-1];
                else if(j==0) curr[j]+=prev[j];
                else curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        return space(grid,m,n);
    }
};
