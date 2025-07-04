// LEETCODE LINK : https://leetcode.com/problems/number-of-longest-increasing-subsequence/submissions/1685713266/

#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), maxLen = 1, res = 0;
    vector<int> len(n, 1), count(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                } else if (len[j] + 1 == len[i]) {
                    count[i] += count[j];
                }
            }
        }
        maxLen = max(maxLen, len[i]);
    }
    for (int i = 0; i < n; ++i)
        if (len[i] == maxLen)
            res += count[i];
    return res;
}

};