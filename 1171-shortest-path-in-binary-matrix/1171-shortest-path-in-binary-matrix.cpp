class Solution {
public:
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    bool isValid(int x, int y, int r, int c) {
        return (x >= 0 && x < r && y >= 0 && y < c);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = true;
        dist[0][0] = 1; // start with 1 step

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
                return dist[x][y]; // reached destination

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny, n, n) && grid[nx][ny] == 0 && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }

        return -1; // no path found
    }
};
