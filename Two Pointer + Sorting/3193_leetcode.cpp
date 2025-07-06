// LEETCODE LINK : https://leetcode.com/problems/count-the-number-of-inversions/submissions/1688113185/

#include <vector>
#include <algorithm>
using namespace std;

int numberOfPermutations(int n, vector<vector<int>>& requirements) {
    const int MOD = 1e9 + 7;
    vector<int> req(n, -1);
    for (auto& r : requirements)
        req[r[0]] = r[1];

    vector<vector<int>> dp(n + 1, vector<int>(n * (n - 1) / 2 + 1, 0));
    dp[0][0] = 1;

    for (int len = 1; len <= n; ++len) {
        for (int inv = 0; inv <= len * (len - 1) / 2; ++inv) {
            for (int k = 0; k < len; ++k) {
                if (inv >= k)
                    dp[len][inv] = (dp[len][inv] + dp[len - 1][inv - k]) % MOD;
            }
        }
    }

    vector<vector<int>> dp2(n + 1, vector<int>(n * (n - 1) / 2 + 1, 0));
    dp2[0][0] = 1;

    for (int len = 1; len <= n; ++len) {
        for (int inv = 0; inv <= len * (len - 1) / 2; ++inv) {
            for (int k = 0; k < len; ++k) {
                if (inv >= k)
                    dp2[len][inv] = (dp2[len][inv] + dp2[len - 1][inv - k]) % MOD;
            }
        }
        if (req[len - 1] != -1) {
            for (int inv = 0; inv <= len * (len - 1) / 2; ++inv) {
                if (inv != req[len - 1])
                    dp2[len][inv] = 0;
            }
        }
    }

    int res = 0;
    for (int inv = 0; inv <= n * (n - 1) / 2; ++inv)
        res = (res + dp2[n][inv]) % MOD;
    return res;
}
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
    const int MOD = 1e9 + 7;
    int maxInv = n * (n - 1) / 2;
    vector<int> req(n, -1);
    for (auto& r : requirements)
        req[r[0]] = r[1];

    vector<int> dp(maxInv + 1, 0), ndp(maxInv + 1, 0);
    dp[0] = 1;

    for (int len = 1; len <= n; ++len) {
        fill(ndp.begin(), ndp.end(), 0);
        int currMaxInv = len * (len - 1) / 2;

        vector<int> prefix(currMaxInv + 2, 0);
        for (int i = 0; i <= currMaxInv; ++i)
            prefix[i + 1] = (prefix[i] + dp[i]) % MOD;

        for (int inv = 0; inv <= currMaxInv; ++inv) {
            int lo = max(0, inv - (len - 1));
            ndp[inv] = (prefix[inv + 1] - prefix[lo] + MOD) % MOD;
        }

        if (req[len - 1] != -1) {
            fill(ndp.begin(), ndp.end(), 0);
            if (req[len - 1] <= currMaxInv)
                ndp[req[len - 1]] = prefix[req[len - 1] + 1] - prefix[max(0, req[len - 1] - (len - 1))];
            if (ndp[req[len - 1]] < 0) ndp[req[len - 1]] += MOD;
        }

        swap(dp, ndp);
    }

    int res = 0;
    for (int x : dp) res = (res + x) % MOD;
    return res;
}
};