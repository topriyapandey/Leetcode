#include <vector>
#include <algorithm>

class Solution {
private:
    int memo[501][501];
    int prefixSum[501];

    int getSum(int i, int j) {
        return prefixSum[j + 1] - prefixSum[i];
    }

    int solve(int i, int j, const std::vector<int>& stoneValue) {
        if (i == j) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int maxScore = 0;

        for (int k = i; k < j; ++k) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                maxScore = std::max(maxScore, leftSum + solve(i, k, stoneValue));
            } else if (leftSum > rightSum) {
                maxScore = std::max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            } else {
                int takeLeft = leftSum + solve(i, k, stoneValue);
                int takeRight = rightSum + solve(k + 1, j, stoneValue);
                maxScore = std::max(maxScore, std::max(takeLeft, takeRight));
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j] = -1;
            }
        }

        prefixSum[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};