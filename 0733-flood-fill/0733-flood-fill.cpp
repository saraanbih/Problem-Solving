class Solution {
public:
    bool isValid(int i,int j,int r,int c){
        return (i >= 0 && i < r && j >= 0 && j < c);
    }
    void dfs(vector<vector<int>>& image,int i,int j,int r,int c,int old,
    int nc){
        if(!isValid(i,j,r,c) || image[i][j] != old)return;
        image[i][j] = nc;
        dfs(image,i,j-1,r,c,old,nc);
        dfs(image,i,j+1,r,c,old,nc);
        dfs(image,i+1,j,r,c,old,nc);
        dfs(image,i-1,j,r,c,old,nc);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size(),c=image[0].size();
        int old = image[sr][sc];
        if(old != color)dfs(image,sr,sc,r,c,old,color);
        return image;;
    }
};