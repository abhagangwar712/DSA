// LEETCODE LINK : https://leetcode.com/problems/majority-element/submissions/1688099972/?envType=problem-list-v2&envId=sorting

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

};