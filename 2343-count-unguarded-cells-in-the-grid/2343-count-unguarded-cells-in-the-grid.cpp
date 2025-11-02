class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    bool valid(int i,int j,int r,int c){
        return (i >= 0 && i < r && j >= 0 && j < c);
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        for(auto &g : guards){
            grid[g[0]][g[1]] = 0;
        }
        for(auto &w : walls){
            grid[w[0]][w[1]] = 1;
        }

        for(auto &g : guards){
            int x = g[0], y = g[1];
            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k + 1];
                while (valid(nx, ny, m, n) && grid[nx][ny] != 0 && grid[nx][ny] != 1) {
                    grid[nx][ny] = 2; 
                    nx += dir[k];
                    ny += dir[k + 1];
                }
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == -1)ans++;
            }
                
        }
        return ans;
    }
};