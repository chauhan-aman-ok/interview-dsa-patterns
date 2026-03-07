
// METHOD 1: NO DP YET
// normal recursion code - 
//time complexity - O(2^n)
// space complexity - O(n) -recursion stack


#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==0 || n==1) return n;
    return fib(n-1)+fib(n-2);
}

int main() {
	// your code goes here
cout<<fib(6);
}


// METHOD 2 : DP (MEMORIZATION)
// recursion + memorization
// - time complexity - O(n)
// space complexity - O(n) (recurion stack) + O(n) (dp array) = O(n)

#include <bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp){
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]= fib(n-1,dp)+fib(n-2,dp);
}

int main() {
	// your code goes here
	int n=6;
	vector<int> dp(n+1,-1);
cout<<fib(n,dp);
}

// METHOD 3 : DP (TABULATION)
//  no recursion, iterative approach
// - time complexity - O(n)
// space complexity -  O(n) (dp array) 
int tabulation(int n,vector<int> &dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main() {
	// your code goes here
	int n=6;
	vector<int> dp(n+1,-1);
cout<<tabulation(n,dp);
}





