// LEETCODE 69. Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        long long l=1,h=x;
        int ans;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(mid*mid<=x){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};
