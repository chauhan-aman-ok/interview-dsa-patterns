// problem 9 : leetcode 1109. Corporate Flight Bookings
// topics- difference array technique + prefix sum
// difference array technique - 

cpp code- 

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        for(int i=0;i<bookings.size();i++){
            int l=bookings[i][0];
            int r=bookings[i][1];
            int seats=bookings[i][2];
            res[l-1]+=seats;
            if(r<n) res[r]-=seats;
        }
        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
        }
        return res;
    }
};

java code-

class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] res=new int[n];
        for(int i=0;i<bookings.length;i++){
            int first=bookings[i][0];
            int last=bookings[i][1];
            int seats=bookings[i][2];
            res[first-1]+=seats;
            if(last<n) res[last-1+1]-=seats;
        }
        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
        }
        return res;
    }
}





