class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0 || grid[0].size() == 0) return false;
        int c = grid[0].size();

        vector<long long> row(r, 0), col(c, 0); // use long long
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        long long tr = accumulate(row.begin(), row.end(), 0LL); // use 0LL to force long long
        long long var = 0;
        for (int i = 0; i < r - 1; i++) {
            var += row[i];
            if (var * 2 == tr) return true;
        }

        long long tc = accumulate(col.begin(), col.end(), 0LL);
        var = 0;
        for (int i = 0; i < c - 1; i++) {
            var += col[i];
            if (var * 2 == tc) return true;
        }

        return false;
    }
};