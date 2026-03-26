using System;

public class Solution
{
    public bool CanPartitionGrid(int[][] grid)
    {
        int m = grid.Length, n = grid[0].Length;

        long total = 0;
        foreach (var row in grid)
            foreach (var val in row)
                total += val;

        // horizontal cuts
        long topSum = 0;
        for (int r = 0; r < m - 1; r++)
        {
            for (int c = 0; c < n; c++)
                topSum += grid[r][c];

            long bottomSum = total - topSum;

            if (Check(grid, topSum, bottomSum,
                      0, r, 0, n - 1,
                      r + 1, m - 1, 0, n - 1))
                return true;
        }

        // vertical cuts
        long leftSum = 0;
        for (int c = 0; c < n - 1; c++)
        {
            for (int r = 0; r < m; r++)
                leftSum += grid[r][c];

            long rightSum = total - leftSum;

            if (Check(grid, leftSum, rightSum,
                      0, m - 1, 0, c,
                      0, m - 1, c + 1, n - 1))
                return true;
        }

        return false;
    }

    private bool Check(int[][] grid,
                       long A, long B,
                       int r1A, int r2A, int c1A, int c2A,
                       int r1B, int r2B, int c1B, int c2B)
    {
        if (A == B) return true;

        long diff = Math.Abs(A - B);

        // determine which side to remove from
        if (A > B)
        {
            return CanRemove(grid, diff, r1A, r2A, c1A, c2A);
        }
        else
        {
            return CanRemove(grid, diff, r1B, r2B, c1B, c2B);
        }
    }

    private bool CanRemove(int[][] grid, long val,
                           int r1, int r2, int c1, int c2)
    {
        for (int r = r1; r <= r2; r++)
        {
            for (int c = c1; c <= c2; c++)
            {
                if (grid[r][c] == val &&
                    IsSafeToRemove(r, c, r1, r2, c1, c2))
                {
                    return true;
                }
            }
        }
        return false;
    }

    private bool IsSafeToRemove(int r, int c,
                               int r1, int r2, int c1, int c2)
    {
        int height = r2 - r1 + 1;
        int width = c2 - c1 + 1;

        // single row or column → always safe
        if (height == 1 || width == 1)
            return true;

        // must be on boundary
        return (r == r1 || r == r2 || c == c1 || c == c2);
    }
}