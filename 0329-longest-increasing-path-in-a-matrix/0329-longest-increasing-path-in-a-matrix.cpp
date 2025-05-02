class Solution { 
public:
    vector<int> dir = {0,1,0,-1,0};
    inline bool isValid(int x,int y,int r,int c){
        return (x >= 0 && x < r && y >= 0 && y < c);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int r = matrix.size(),c=matrix[0].size();
       vector<vector<int>> indegree(r,vector<int>(c,0));
       for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            for(int d=0;d<4;d++){
                int nx = i+dir[d];
                int ny = j+dir[d+1];
                if(isValid(nx,ny,r,c) && matrix[nx][ny] > matrix[i][j])indegree[nx][ny]++;
            }
         }
       }
       queue<pair<int,int>> q;
       for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            if(indegree[i][j] == 0)q.push({i,j});
         }
        }
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[x,y] = q.front(); q.pop();
                 for(int d=0;d<4;d++){
                    int nx = x+dir[d];
                    int ny = y+dir[d+1];
                    if(isValid(nx,ny,r,c) && matrix[nx][ny] > matrix[x][y]){
                        if(--indegree[nx][ny] == 0)q.emplace(nx,ny);
                    }
                }
            }
            res++;
        }
        return res;
    }
};
