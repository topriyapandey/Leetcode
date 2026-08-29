class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }

        string t = "1" + s + "1";
        int n = t.size();

        int ans = ones;

        for (int i = 1; i < n - 1; ) {
            if (t[i] == '0') {
                int zeroStart = i;

                while (i < n - 1 && t[i] == '0') i++;

                int zeroEnd = i - 1;

                if (i < n - 1 && t[i] == '1') {
                    int oneStart = i;

                    while (i < n - 1 && t[i] == '1') i++;

                    int oneEnd = i - 1;

                    if (oneStart > 0 && oneEnd < n - 1 &&
                        t[oneStart - 1] == '0' &&
                        t[oneEnd + 1] == '0') {

                        int leftZeros = 0;
                        int rightZeros = 0;

                        int l = oneStart - 1;
                        while (l >= 1 && t[l] == '0') {
                            leftZeros++;
                            l--;
                        }

                        int r = oneEnd + 1;
                        while (r < n - 0 && t[r] == '0') {
                            rightZeros++;
                            r++;
                        }

                        ans = max(ans, ones + leftZeros + rightZeros);
                    }
                }
            } else {
                i++;
            }
        }

        return ans;
    }
};