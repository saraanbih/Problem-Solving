class Solution {
public:
    vector<int> d = {0,1,0,-1,0};
    bool isValid(int x,int y,int r,int c){
        return (x>=0) && (x<r) && (y>=0) && (y<c);
    }
    bool dfs(int x,int y,int r,int c,int idx,string &word,vector<vector<char>>& board,vector<vector<bool>>& vis){
        if(idx == word.size()) return true;
        
        vis[x][y] = true;
        
        for(int i=0;i<4;i++){
            int nx = x + d[i];
            int ny = y + d[i+1];
            if(isValid(nx,ny,r,c) && !vis[nx][ny] && board[nx][ny] == word[idx]){
               if(dfs(nx,ny,r,c,idx+1,word,board,vis)) return true;
            }
        }

        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(),c=board[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,r,c,1,word,board,vis)) return true;
                }
            }
        }
        return false;
    }
};