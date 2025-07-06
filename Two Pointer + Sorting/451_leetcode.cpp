// LEETCODE LINK : https://leetcode.com/problems/sort-characters-by-frequency/submissions/1688103106/?envType=problem-list-v2&envId=sorting

#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    priority_queue<pair<int, char>> pq;
    for (auto& [ch, count] : freq)
        pq.push({count, ch});

    string result;
    while (!pq.empty()) {
        auto [count, ch] = pq.top(); pq.pop();
        result += string(count, ch);
    }
    return result;
}

};