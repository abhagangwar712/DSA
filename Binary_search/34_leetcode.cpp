//LEETCODE LINK : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1683943426/

#include <vector>
using namespace std;

class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                res = mid;
                high = mid - 1; 
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return res;
   }

int findLast(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            res = mid;
            low = mid + 1; 
        } else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return res;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {findFirst(nums, target), findLast(nums, target)};
}

};
