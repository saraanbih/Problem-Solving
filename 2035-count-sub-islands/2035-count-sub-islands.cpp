class Solution {
public:
     vector<int> d = {0,1,0,-1,0};
    inline bool isValid(int x,int y,int r,int c){
        return (x >= 0 && x < r && y >= 0 && y < c);
    }
    bool dfs(int x,int y,int r,int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<bool>> &vis){
        bool sub = true;
        if(grid1[x][y] == 0) sub = false;
        vis[x][y] = true;
         for(int i=0;i<4;i++){
            int nx = x + d[i];
            int ny = y + d[i+1];
            if(isValid(nx,ny,r,c) && !vis[nx][ny] && grid2[nx][ny] == 1){
                bool ans = dfs(nx,ny,r,c,grid1,grid2,vis);
                sub = sub && ans;
            }
        }
        return sub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid2.size(),c=grid2[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int cnt = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && grid2[i][j] == 1){
                    if(dfs(i,j,r,c,grid1,grid2,vis))cnt++;
                }
            }
        }
        return cnt;
    }
};
