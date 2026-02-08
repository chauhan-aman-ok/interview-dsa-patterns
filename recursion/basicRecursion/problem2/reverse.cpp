problem 2 : leetcode 344. Reverse String

cpp code - 

class Solution {
public:
    void helper(vector<char>& s,int l,int r){
        if(l>=r) return;
        swap(s,l,r);
        helper(s,++l,--r);
    }
    void swap(vector<char>& s,int l,int r){
        char temp=s[l];
        s[l]=s[r];
        s[r]=temp;
    }
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};

