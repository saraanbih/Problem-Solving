class Solution {
public:
    inline bool isValid(int i, int j, int r, int c){
        return (i >= 0 && i < r && j >= 0 && j < c);
    }

    void dfs(vector<vector<int>>& image, int i, int j, int color, int r, int c, int oldColor){
        if (!isValid(i, j, r, c) || image[i][j] != oldColor)
            return;

        image[i][j] = color;

        dfs(image, i - 1, j, color, r, c, oldColor); 
        dfs(image, i + 1, j, color, r, c, oldColor); 
        dfs(image, i, j - 1, color, r, c, oldColor); 
        dfs(image, i, j + 1, color, r, c, oldColor); 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size(), c = image[0].size();
        int oldColor = image[sr][sc];

        if (oldColor != color) {
            dfs(image, sr, sc, color, r, c, oldColor);
        }

        return image;
    }
};
