class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool is_valid(int r,int c,int nr,int nc){
        return (nr >= 0 && nr < r && nc >= 0 && nc < c);
    }
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>>& heights){
        int n = heights.size(), m = heights[0].size();
        vis[r][c] = 1;
        for(auto &d : dir){
            int nr = r + d[0],nc = c + d[1];
            if(is_valid(n,m,nr,nc) && !vis[nr][nc] && heights[nr][nc] 
            >= heights[r][c]){
                dfs(nr,nc,vis,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(),c = heights[0].size();
        vector<vector<int>> p(r,vector<int>(c,0));
        vector<vector<int>> a(r,vector<int>(c,0));

        for(int i=0;i<r;i++)dfs(i,0,p,heights);
        for(int j=0;j<c;j++)dfs(0,j,p,heights);

        for(int i=0;i<r;i++)dfs(i,c-1,a,heights);
        for(int j=0;j<c;j++)dfs(r-1,j,a,heights);

        vector<vector<int>> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(p[i][j] && a[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};