// LEETCODE LINK : https://leetcode.com/problems/subsets/submissions/1684723893/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {

        result.push_back(current);
        
        for (int i = index; i < nums.size(); ++i) {

            current.push_back(nums[i]);
            
            backtrack(nums, i + 1, current, result);
        
            current.pop_back();
        }
    }
};