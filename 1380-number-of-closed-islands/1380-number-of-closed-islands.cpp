class Solution {
public:
    vector<int> d = {0,1,0,-1,0}; 
    bool isValid(int x,int y,int r,int c){
        return (x >= 0 && x < r && y >= 0 && y < c);
    }
    bool dfs(int x, int y, int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (!isValid(x,y,r,c)) return false;

        if (grid[x][y] == 1 || vis[x][y]) return true;        

        vis[x][y] = true;
        bool isClosed = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i];
            int ny = y + d[i+1];
            if (!dfs(nx,ny, r,c, grid, vis)) isClosed = false;
        }

        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(r, vector<bool>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0 && !vis[i][j] && dfs(i, j, r,c, grid, vis))
                    cnt++;
            }
        }
        return cnt;
    }

    
};