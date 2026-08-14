#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        std::unordered_map<char, int> count;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right]]++;

            while (count[s[right]] > 2) {
                count[s[left]]--;
                left++;
            }

            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};