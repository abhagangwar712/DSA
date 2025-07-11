// LEETCODE LINK : https://leetcode.com/problems/partition-equal-subset-sum/submissions/1684896995/

#include <vector>
#include <algorithm>    
using namespace std;

class Solution {
public:
   bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int num : nums) {
        total += num;
    }

    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true; 

    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}
};