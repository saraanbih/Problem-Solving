public class Solution {

    private bool IsMagic(int[][] grid,int row,int col)
    {
        bool []Check = new bool[10];

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int var = grid[row+i][col+j];
                if(var < 1 ||  var > 9||Check[var]  ) return false;
                Check[var] = true; 
            }
        }

        int diagonal1 = grid[row][col] + grid[row + 1][col + 1] + grid[row+2][col+2];
        int diagonal2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if(diagonal1 != diagonal2) return false;

        int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int row2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int row3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];
        if(!((row1 == diagonal1) && (row2 == diagonal1) && (row3 == diagonal1)))
            return false;

        int col1 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int col2 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int col3 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];
        if(!((col1 == diagonal1) && (col2 == diagonal1) && (col3 == diagonal1)))
            return false;
        
        return true;
    }


    public int NumMagicSquaresInside(int[][] grid) 
    {
        int res =0;
        int NumRow = grid.Length;
        int NumCol = grid[0].Length;

        for(int r = 0;r <= NumRow-3;r++)
        {
            for(int c=0;c <= NumCol-3;c++)
            {
                if(IsMagic(grid,r,c)) res++;
            }
        }
        return res;
    }
}