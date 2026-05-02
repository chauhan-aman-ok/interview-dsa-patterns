// leetcode 239, 

// wrong code-
//cannot implemented by queue, can only implemented be deque only
// reason - use this test case -> vector - [1,3,1,2,0,5] k=3, ans=[3,3,2,5]
#include <bits/stdc++.h>
using namespace std;

 vector<int> maxSlidingWindow(vector<int> nums, int k) {
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[q.front()]<nums[i]){
                q.pop();
            }
            q.push(i);
        }
        int i=0;
        int j=k-1;
        while(j<nums.size()){
            ans.push_back(nums[q.front()]);
            i++;j++;

            while(!q.empty() && q.front()<i){
                q.pop();
            }
            while(!q.empty() && nums[q.front()]<nums[j]){
                q.pop();
            }
            q.push(j);
        }
        return ans;
    }
int main() {
    vector<int> b = maxSlidingWindow(vector<int>({1,3,-1,-3,5,3,6,7}), 3);
    for(auto x:b) cout<<x<<" ";
}

// correct code-
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        int i=0;
        int j=k-1;
        while(j<nums.size()){
            ans.push_back(nums[q.front()]);
            i++;j++;
            
            while(!q.empty() && q.front()<i){
                q.pop_front();
            }
            if(j==nums.size()) return ans;
            while(!q.empty() && nums[q.back()]<nums[j]){
                q.pop_back();
            }
            q.push_back(j);
        }
        return ans;
    }
};
