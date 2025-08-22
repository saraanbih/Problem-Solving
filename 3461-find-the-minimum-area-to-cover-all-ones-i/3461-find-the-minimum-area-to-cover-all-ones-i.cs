public class Solution {
    public int MinimumArea(int[][] grid) {
        int mx_row = int.MinValue,mx_col = int.MinValue;
        int mn_row = int.MaxValue,mn_col = int.MaxValue;

        for(int i =0;i<grid.Length;i++){
            for(int j=0;j<grid[0].Length;j++){
                if(grid[i][j] == 1){
                    mn_row = Math.Min(mn_row,i);
                    mn_col = Math.Min(mn_col,j);
                    mx_row = Math.Max(mx_row,i);
                    mx_col = Math.Max(mx_col,j);
                }
            }
        }
        return ((mx_row - mn_row + 1) * (mx_col - mn_col +1));
    }
}