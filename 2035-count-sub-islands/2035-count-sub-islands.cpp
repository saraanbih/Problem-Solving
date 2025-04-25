class Solution {
    
    vector<int> dir = {0, 1, 0, -1, 0};

    inline bool isValid(int x, int y, int r, int c) {
        return (x >= 0 && x < r && y >= 0 && y < c);
    }

    bool dfs(int x, int y,int r,int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis) {

        bool is_subland = true;

        if (grid1[x][y] == 0) is_subland = false;

        vis[x][y] = true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i];
            int ny = y + dir[i + 1];

            if (isValid(nx, ny, r, c) && !vis[nx][ny] && grid2[nx][ny] == 1) {
                bool ans = dfs(nx, ny,r,c, grid1, grid2, vis);

                is_subland = is_subland && ans;
            }
        }

        return is_subland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid2.size();
        int c = grid2[0].size();

        vector<vector<bool>> vis(r, vector<bool>(c, false));
        int cnt = 0;

        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                if (!vis[x][y] && grid2[x][y] == 1) {
                    if (dfs(x, y,r,c, grid1, grid2, vis)) cnt++;
                }
            }
        }

        return cnt;
    }
};
