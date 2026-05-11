// time complexity - O(n^2)
// space complexity - O(n)


class Solution {
public:
    int tabulation(vector<vector<int>> &triangle){
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<int> prev(n);
      prev[0]=triangle[0][0];
      for(int i=1;i<m;i++){
        vector<int> curr(triangle[i].size());
        for(int j=0;j<triangle[i].size();j++){
            if(i==0 && j==0){
                curr[j]=prev[j];continue;
            }
            if(j==0){
                curr[j]=triangle[i][j]+prev[j];
            }else if(j==triangle[i].size()-1){
                curr[j]=triangle[i][j]+prev[j-1];
            }else{
                curr[j]=triangle[i][j]+min(prev[j],prev[j-1]);
            }
        }
        prev=curr;
      }
      int ans=INT_MAX;
      for(int i=0;i<n;i++){
        ans=min(ans,prev[i]);
      }
      return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return tabulation(triangle);
    }
};
