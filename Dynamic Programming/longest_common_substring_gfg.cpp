// GFG LINK : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.size(), m = s2.size(), result = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }
        }
    }
    return result;
}

};