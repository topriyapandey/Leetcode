class Solution {
public:
    void placequeen(int& ans, int& n, vector<bool>& ld, vector<bool>& rd, vector<bool>& col, int i) {
        if(i == n) {
            ans++;
            return;
        }

        for(int j = 0; j < n; j++) {
            if(col[j] || ld[n - 1 + i - j] || rd[i + j])
                continue;

            col[j] = true;
            ld[n - 1 + i - j] = true;
            rd[i + j] = true;

            placequeen(ans, n, ld, rd, col, i + 1);

            col[j] = false;
            ld[n - 1 + i - j] = false;
            rd[i + j] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> ld(2 * n - 1, false);
        vector<bool> rd(2 * n - 1, false);
        vector<bool> col(n, false);

        int ans = 0;

        placequeen(ans, n, ld, rd, col, 0);

        return ans;
    }
};