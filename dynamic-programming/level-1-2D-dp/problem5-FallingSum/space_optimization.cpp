// space optimization - 
// time compplexity - O(m*n)
// space comlexity - O(n)


class Solution {
public:
    
    int space(vector<vector<int>>& grid,int m,int n){
        vector<int> prev(n);
        
        for(int i=0;i<m;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                if(i==0){
                  curr[j]=grid[0][j];
                }else if(j==0){
                    curr[j]=grid[i][j]+min(prev[j],prev[j+1]);
                }else if(j==n-1){
                    curr[j]=grid[i][j]+min(prev[j],prev[j-1]);
                }else{
                    curr[j]=grid[i][j]+min(prev[j],min(prev[j-1],prev[j+1]));
                }
            }
            prev=curr;
        }

        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,prev[i]);
        }
        return mn;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        return space(grid,m,n);
    }
};
