// LEETCODE LINK : https://leetcode.com/problems/climbing-stairs/submissions/1684859506/

class Solution {
public:
    int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; ++i) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

};