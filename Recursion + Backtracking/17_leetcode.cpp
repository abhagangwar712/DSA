// LEETCODE LINK : https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1684727733/

#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

    vector<string> result;
    vector<string> mapping = {
        "",     "",     "abc",  "def", "ghi", 
        "jkl",  "mno",  "pqrs", "tuv", "wxyz"
    };

    string current;

    function<void(int)> backtrack = [&](int index) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(index + 1);
            current.pop_back();
        }
    };

    backtrack(0);
    return result;
    }
};