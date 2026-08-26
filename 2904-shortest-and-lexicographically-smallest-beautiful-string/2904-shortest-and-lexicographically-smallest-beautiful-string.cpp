class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int left = 0, ones = 0, minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1')
                ones++;

            while (ones == k) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    ans = s.substr(left, len);
                } else if (len == minLen) {
                    ans = min(ans, s.substr(left, len));
                }

                if (s[left] == '1')
                    ones--;
                left++;
            }
        }

        return ans;
    }
};