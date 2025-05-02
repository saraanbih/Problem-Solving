class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0}; 
    bool isValid(int x, int y, int r, int c) {
        return x >= 0 && x < r && y >= 0 && y < c;
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < r; ++i) {
            if (board[i][0] == 'O') q.emplace(i, 0);
            if (board[i][c - 1] == 'O') q.emplace(i, c - 1);
        }

        for (int j = 0; j < c; ++j) {
            if (board[0][j] == 'O') q.emplace(0, j);
            if (board[r - 1][j] == 'O') q.emplace(r - 1, j);
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (!isValid(x, y, r, c) || board[x][y] != 'O') continue;

            board[x][y] = '.';  

            for (int d = 0; d < 4; ++d) {
                int nx = x + dir[d];
                int ny = y + dir[d + 1];
                q.emplace(nx, ny);
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '.') board[i][j] = 'O';
            }
        }
    }
};
