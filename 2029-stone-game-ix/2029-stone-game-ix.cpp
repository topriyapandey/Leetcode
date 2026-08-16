#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int c[3] = {0, 0, 0};
        for (int stone : stones) {
            c[stone % 3]++;
        }

        if (c[0] % 2 == 0) {
            return c[1] >= 1 && c[2] >= 1;
        }
        return std::abs(c[1] - c[2]) > 2;
    }
};