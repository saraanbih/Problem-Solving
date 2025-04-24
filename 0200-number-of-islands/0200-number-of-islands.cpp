class Solution {
public:
    vector<int> d = {0,1,0,-1,0};
    bool isValid(int x,int y,int r,int c)
       { return (x>=0) && (y>=0) && (x<r) && (y<c);}
    void dfs(int x,int y,int r,int c,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        vis[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + d[i];
            int ny = y + d[i+1];
            if(isValid(nx,ny,r,c) and !vis[nx][ny] and grid[nx][ny] == '1') dfs(nx,ny,r,c,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int r = grid.size(),c=grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int cnt = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i,j,r,c,grid,vis);
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};