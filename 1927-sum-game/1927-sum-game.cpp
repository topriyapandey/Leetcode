class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;

        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < mid; i++) {
            if (num[i] == '?')
                q1++;
            else
                sum1 += num[i] - '0';
        }

        for (int i = mid; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                sum2 += num[i] - '0';
        }

        int diff = sum1 - sum2;
        int qDiff = q1 - q2;

        if (qDiff % 2 != 0)
            return true;

        if (qDiff == 0)
            return diff != 0;

        int target = -(qDiff / 2) * 9;

        return diff != target;
    }
};