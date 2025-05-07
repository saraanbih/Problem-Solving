class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};

    bool isValid(int x, int y, int r, int c) {
        return (x >= 0 && x < r && y >= 0 && y < c);
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> v(n, vector<bool>(m, false));

        d[0][0] = 0;

        // (dis, x, y) - so priority_queue sorts by distance ascending
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> q;
        q.push({0, 0, 0}); // (distance, x, y)

        while (!q.empty()) {
            auto [dist, x, y] = q.top(); q.pop();
            if (v[x][y]) continue;
            v[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if (!isValid(nx, ny, n, m)) continue;

                int newDist = max(d[x][y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > newDist) {
                    d[nx][ny] = newDist;
                    q.push({newDist, nx, ny});
                }
            }
        }

        return d[n - 1][m - 1];
    }
};
