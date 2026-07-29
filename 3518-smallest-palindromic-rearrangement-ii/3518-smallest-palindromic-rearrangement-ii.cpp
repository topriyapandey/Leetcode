class Solution {
public:
    static const int LIMIT = 1000000;

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        __int128 res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > LIMIT)
                return LIMIT + 1;
        }

        return (long long)res;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt)
            total += x;

        long long ways = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;

            long long c = comb(rem, x);

            __int128 cur = (__int128)ways * c;

            if (cur > LIMIT)
                ways = LIMIT + 1;
            else
                ways = (long long)cur;

            rem -= x;
        }

        return min((long long)LIMIT + 1, ways);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        string left = "";
        int len = 0;
        for (int x : half)
            len += x;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};