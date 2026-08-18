#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> subarrayCount;

        for (int i = 0; i <= n - k; ++i) {
            std::unordered_set<int> uniqueInSubarray;
            for (int j = i; j < i + k; ++j) {
                uniqueInSubarray.insert(nums[j]);
            }
            for (int val : uniqueInSubarray) {
                subarrayCount[val]++;
            }
        }

        int maxVal = -1;
        for (auto const& [val, count] : subarrayCount) {
            if (count == 1) {
                maxVal = std::max(maxVal, val);
            }
        }

        return maxVal;
    }
};