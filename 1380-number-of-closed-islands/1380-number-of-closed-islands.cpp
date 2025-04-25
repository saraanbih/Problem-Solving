class Solution {
public:
    vector<int> d = {0,1,0,-1,0};
    inline bool isValid(int x,int y,int r,int c){
        return (x >= 0 && x < r && y >= 0 && y < c);
    }
    bool dfs(int x,int y,int r,int c,vector<vector<int>>& grid,vector<vector<bool>> &vis){
        if(!isValid(x,y,r,c)) return false;
        if(grid[x][y] == 1 || vis[x][y]) return true;
        vis[x][y] = true;
        bool closed = true;
        for(int i=0;i<4;i++){
            int nx = x + d[i];
            int ny = y + d[i+1];
            if(!dfs(nx,ny,r,c,grid,vis))closed = false;
        } 
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
       int r = grid.size(),c=grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int cnt = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 0 && !vis[i][j] && dfs(i,j,r,c,grid,vis)){
                    cnt++;
                }
            }
        }
        return cnt++;
    }
};