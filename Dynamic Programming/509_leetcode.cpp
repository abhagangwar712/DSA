// LEETCODE LINK : https://leetcode.com/problems/fibonacci-number/submissions/1684846729/

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else{
            return fib(n-1)+fib(n-2);
        }
    }
};