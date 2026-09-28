class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int x, int y,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m=grid[0].size();
        if (i >= n)
            return 0;

        if (dp[i][x][y] != -1)
            return dp[i][x][y];

        int cherry = grid[i][x];

        if (x != y)
            cherry += grid[i][y];

        int ans = 0;

        for (int val1 = -1; val1 <= 1; val1++) {
            for (int val2 = -1; val2 <= 1; val2++) {

                int new_row = i + 1;
                int new_c1 = x + val1;
                int new_c2 = y + val2;

                if (new_c1 >= 0 && new_c1 < m &&
                    new_c2 >= 0 && new_c2 < m) {

                    ans = max(ans,
                        solve(grid, new_row, new_c1, new_c2, dp));
                }
            }
        }

        return dp[i][x][y] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m+1, vector<int>(m+1, -1))
        );

        return solve(grid, 0, 0, m - 1, dp);
    }
};