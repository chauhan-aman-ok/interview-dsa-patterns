// space opitmization - 
// space complexity - O(n)


class Solution {
public:
    int space(vector<vector<int>>& grid,int m,int n){
        vector<int> prev(n);
        prev[0]=grid[0][0];
        for(int i=0;i<m;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    curr[j]=prev[j];
                    continue;}
                else if(i==0) curr[j]=grid[i][j]+curr[j-1];
                else if(j==0) curr[j]=grid[i][j]+prev[j];
                else curr[j]=grid[i][j]+min(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1) return grid[0][0];
        return space(grid,m,n);
    }
};
