// LEETCODE LINK : https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/1684177445/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (mid % 2 == 1) mid--;

        if (nums[mid] == nums[mid + 1]) {
            
            low = mid + 2;
        } else {
            
            high = mid;
        }
    }
    
    return nums[low];
    }
};
