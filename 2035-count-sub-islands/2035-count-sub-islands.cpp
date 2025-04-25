class Solution {
    vector<int> dir = {0, 1, 0, -1, 0}; // الاتجاهات: يمين، تحت، شمال، فوق

    // دالة تتحقق هل النقطة داخل حدود المصفوفة
    inline bool isValid(int x, int y, int r, int c) {
        return (x >= 0 && x < r && y >= 0 && y < c);
    }

    // DFS: ترجع true لو الجزيرة اللي بنزورها كلها موجودة في grid1
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis) {
        int r = grid2.size();
        int c = grid2[0].size();

        // نبدأ بافتراض إن الجزيرة ممكن تكون sub-island
        bool isSubIsLand = true;

        // لو الخلية المقابلة في grid1 مية (0)، يبقى دي مش جزء من sub-island
        if (grid1[x][y] == 0) isSubIsLand = false;

        // نزور الخلية الحالية
        vis[x][y] = true;

        // نلف على الأربع اتجاهات
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i];
            int ny = y + dir[i + 1];

            // لو الجار داخل الحدود، مش مزور، وفيه أرض (1) في grid2
            if (isValid(nx, ny, r, c) && !vis[nx][ny] && grid2[nx][ny] == 1) {
                // نزوره ونتأكد هل هو كمان موجود في grid1
                bool child = isSubIsland(nx, ny, grid1, grid2, vis);

                // لازم كل الخلايا تكون sub-island
                isSubIsLand = isSubIsLand && child;
            }
        }

        return isSubIsLand;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid2.size();
        int c = grid2[0].size();

        vector<vector<bool>> vis(r, vector<bool>(c, false));
        int subIslandCounts = 0;

        for (int x = 0; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                // نبدأ DFS لو لقينا أرض مش مزورة
                if (!vis[x][y] && grid2[x][y] == 1) {
                    if (isSubIsland(x, y, grid1, grid2, vis)) {
                        subIslandCounts++;
                    }
                }
            }
        }

        return subIslandCounts;
    }
};
