class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        int total = m * n;
        k %= total;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currIdx = i * n + j;
                int newIdx = (currIdx + k) % total;

                int row = newIdx / n;
                int col = newIdx % n;

                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};