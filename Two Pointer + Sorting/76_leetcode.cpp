// LEETCODE LINK : https://leetcode.com/problems/minimum-window-substring/submissions/1686130177/

#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int have = 0, needSize = need.size();
    int left = 0, right = 0, minLen = INT_MAX, start = 0;

    while (right < s.size()) {
        char c = s[right++];
        window[c]++;
        if (need.count(c) && window[c] == need[c]) have++;

        while (have == needSize) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }
            char d = s[left++];
            if (need.count(d) && window[d]-- == need[d]) have--;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

};