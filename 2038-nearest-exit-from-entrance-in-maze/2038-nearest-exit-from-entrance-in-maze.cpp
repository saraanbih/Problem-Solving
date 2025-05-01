class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};

    bool isValid(int x, int y, int r, int c) {
        return (x >= 0 && x < r && y >= 0 && y < c);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size(), c = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = true;

        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            res++;
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i];
                    int ny = y + dir[i + 1];
                    if (isValid(nx, ny, r, c) && maze[nx][ny] == '.' && !vis[nx][ny]) {
                        if (nx == 0 || nx == r - 1 || ny == 0 || ny == c - 1)
                            return res;
                        q.push({nx, ny});
                        vis[nx][ny] = true; // ✅ fix: mark as visited
                    }
                }
            }
        }
        return -1;
    }
};
