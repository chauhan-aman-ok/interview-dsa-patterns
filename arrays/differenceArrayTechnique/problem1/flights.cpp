learn this technique from here = https://www.youtube.com/watch?v=ZHNVmtm08WY&list=PLpIkg8OmuX-Kqkb8DqDe_4-Tiav6ilS_L&index=1

problem 1 : leetcode : 1109. Corporate Flight Bookings

topics - prefix sum/ difference array technique 

cpp code- 

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for(int i=0;i<bookings.size();i++){
            int l=bookings[i][0];
            int r=bookings[i][1];
            int val=bookings[i][2];
            res[l-1]+=val;
            if(r<n) res[r]-=val;
        }
        for(int i=1;i<res.size();i++){
            res[i]+=res[i-1];
        }
        return res;
    }
};



