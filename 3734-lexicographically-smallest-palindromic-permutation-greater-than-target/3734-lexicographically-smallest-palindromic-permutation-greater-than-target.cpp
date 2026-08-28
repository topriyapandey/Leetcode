class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        int halfLen = n / 2;
        string half = "";

        for (int i = 0; i < 26; i++) {
            half.append(cnt[i] / 2, char('a' + i));
        }

        auto makePalindrome = [&](const string& h) {
            string res = h;

            if (n % 2)
                res += mid;

            string rev = h;
            reverse(rev.begin(), rev.end());

            return res + rev;
        };

        string candidate = "";

        function<bool(int, bool)> dfs = [&](int pos, bool greater) {
            if (pos == halfLen) {
                string res = makePalindrome(candidate);

                if (res > target)
                    return true;

                return false;
            }

            for (int i = 0; i < 26; i++) {
                if (cnt[i] < 2)
                    continue;

                char c = char('a' + i);

                if (!greater && c < target[pos])
                    continue;

                bool newGreater = greater || c > target[pos];

                cnt[i] -= 2;
                candidate += c;

                if (dfs(pos + 1, newGreater))
                    return true;

                candidate.pop_back();
                cnt[i] += 2;
            }

            return false;
        };

        if (dfs(0, false))
            return makePalindrome(candidate);

        return "";
    }
};