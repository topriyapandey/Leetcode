class Solution {
public:
    int n;
    vector<int> area = {0, 0};
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = id;
        int cnt = 1;
        for (int k = 0; k < 4; k++) {
            cnt += dfs(grid, i + dx[k], j + dy[k], id);
        }
        return cnt;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area.push_back(dfs(grid, i, j, id));
                    id++;
                }
            }
        }
        int ans = 0;
        for (int i = 2; i < area.size(); i++)
            ans = max(ans, area[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    int curr = 1;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                            grid[ni][nj] > 1) {
                            int islandId = grid[ni][nj];
                            if (st.insert(islandId).second)
                                curr += area[islandId];
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};