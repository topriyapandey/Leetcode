class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        sort(digits.begin(), digits.end(), greater<int>());

        return digits[0] * digits[1];
    }
};