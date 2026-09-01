class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> litter;

        // Find S and all L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // All litter already collected
        if (k == 0)
            return 0;

        // Convert litter positions to bit indexes
        map<pair<int, int>, int> litterId;

        for (int i = 0; i < k; i++) {
            litterId[litter[i]] = i;
        }

        int fullMask = (1 << k) - 1;

        // state = {row, col, energy, mask}
        struct State {
            int r;
            int c;
            int energy;
            int mask;
        };

        queue<State> q;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                State curr = q.front();
                q.pop();

                // All litter collected
                if (curr.mask == fullMask)
                    return moves;

                // Can't move anymore
                if (curr.energy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = curr.r + dr[d];
                    int nc = curr.c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = curr.energy - 1;
                    int newMask = curr.mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[{nr, nc}];
                        newMask |= (1 << id);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Haven't visited this state
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};