// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& nums, int k) {
        // write code here
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(nums[i]<0) q.push(i);
        }
        int i=0;
        int j=k-1;
        while(j<nums.size()){
            
            if(!q.empty()){
                ans.push_back(nums[q.front()]);
            }else ans.push_back(0);
            i++;j++;
        if(nums[j]<0) q.push(j);
        while(!q.empty() && q.front()<i) q.pop();
        }
        return ans;
    }
};
