// LEETCODE LINK : https://leetcode.com/problems/two-sum/submissions/1686115313/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;
        for(int i=0; i<nums.size(); i++){
            int key=target-nums[i];
            if(hm.find(key)!=hm.end()){
                return {hm[key],i};
          
            }
            hm[nums[i]]=i;
        }
        return {};
    }
};