class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        vector<pair<int, int>> litter;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (classroom[i][j] == 'L') {
                    id[i][j] = litter.size();
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0) return 0;

        int totalMask = (1 << k) - 1;

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        queue<tuple<int, int, int, int, int>> q;

        q.push({sx, sy, 0, energy, 0});
        best[sx][sy][0] = energy;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y, mask, currEnergy, moves] = q.front();
            q.pop();

            if (mask == totalMask) return moves;

            if (currEnergy == 0) {
                if (classroom[x][y] != 'R') continue;
                currEnergy = energy;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if (classroom[nx][ny] == 'X')
                    continue;

                if (currEnergy <= 0)
                    continue;

                int newEnergy = currEnergy - 1;

                if (classroom[nx][ny] == 'R')
                    newEnergy = energy;

                int newMask = mask;

                if (classroom[nx][ny] == 'L') {
                    newMask |= (1 << id[nx][ny]);
                }

                if (best[nx][ny][newMask] >= newEnergy)
                    continue;

                best[nx][ny][newMask] = newEnergy;

                q.push({
                    nx,
                    ny,
                    newMask,
                    newEnergy,
                    moves + 1
                });
            }
        }

        return -1;
    }
};