
class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] == 1) {
            return;
        }

        grid[r][c] = 1; // Mark visited

        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Step 1: Remove all land connected to boundaries
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        // Step 2: Count remaining islands
        int count = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};
