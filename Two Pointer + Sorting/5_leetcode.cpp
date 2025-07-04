// LEETCODE LINK : https://leetcode.com/problems/longest-palindromic-substring/submissions/1686124351/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, maxLen = 1;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            --l; ++r;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            --l; ++r;
        }
    }
    return s.substr(start, maxLen);
}

};