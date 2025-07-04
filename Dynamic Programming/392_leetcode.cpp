// LEETCODE LINK : https://leetcode.com/problems/is-subsequence/submissions/1684908982/

#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    return i == s.size();
}

};