// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

class Solution {
  public:
    vector<int> countDistinct(vector<int> &nums, int k) {
        // code here
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        int i=0;
        int j=k-1;
        while(j<nums.size()){
            ans.push_back(mp.size());
            i++;j++;
            
            mp[nums[i-1]]--;
            if(mp[nums[i-1]]==0) mp.erase(nums[i-1]);
            if(j<nums.size()) mp[nums[j]]++;
        }
        return ans;
    }
};
