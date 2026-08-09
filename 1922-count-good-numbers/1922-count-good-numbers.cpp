class Solution {
public:

    const long long MOD = 1000000007;

    long long power(long long a, long long b) {

        long long ans = 1;

        while (b > 0) {

            if (b % 2 == 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;

            b /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};