class Solution {
public:
    static const int MOD = 1000000007;

    int dp[205][201][201];

    int solve(int idx, int g1, int g2, vector<int>& nums) {

        if (idx == nums.size())
            return (g1 != 0 && g2 != 0 && g1 == g2);

        if (dp[idx][g1][g2] != -1)
            return dp[idx][g1][g2];

        long long ans = 0;

        // Ignore current element
        ans += solve(idx + 1, g1, g2, nums);

        // Put in first subsequence
        ans += solve(idx + 1,
                     g1 == 0 ? nums[idx] : gcd(g1, nums[idx]),
                     g2,
                     nums);

        // Put in second subsequence
        ans += solve(idx + 1,
                     g1,
                     g2 == 0 ? nums[idx] : gcd(g2, nums[idx]),
                     nums);

        return dp[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, nums);
    }
};