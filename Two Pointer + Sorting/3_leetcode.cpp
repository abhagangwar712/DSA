// LEETCODE LINK : https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1686126326/

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int start=0;
        int maxl=0;
        for(int end=0; end<s.size(); end++){
            char cc=s[end];
            if(um.find(cc)!=um.end() && um[cc]>=start){
                start=um[cc]+1;
            }
            um[cc]=end;
            maxl=max(maxl, (end-start+1));
        }
        return maxl;
        
    }
};