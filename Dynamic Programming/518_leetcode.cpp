// LEETCODE LINK : https://leetcode.com/problems/coin-change-ii/submissions/1684888223/

#include <vector>
#include <climits>  
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount] > INT_MAX ? 0 : dp[amount];
}


};