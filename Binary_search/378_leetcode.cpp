// LEETCODE LINK : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/1684182895/

#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
    int low = matrix[0][0], high = matrix[n-1][n-1];

    while (low < high) {
        int mid = low + (high - low) / 2;

        int count = 0, j = n - 1;
        for (int i = 0; i < n; ++i) {
            while (j >= 0 && matrix[i][j] > mid) j--;
            count += (j + 1);
        }

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
    }
};
