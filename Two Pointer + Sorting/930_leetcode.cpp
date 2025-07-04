// LEETCODE LINK : https://leetcode.com/problems/binary-subarrays-with-sum/submissions/1686128135/

#include <vector>
#include <unordered_map>    
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixCount.count(sum - goal))
            count += prefixCount[sum - goal];
        prefixCount[sum]++;
    }
    return count;
}

};