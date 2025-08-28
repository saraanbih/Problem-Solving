public class Solution {
    public int[][] SortMatrix(int[][] grid) {
        int n = grid.Length;

        for (int i = 0; i < n; i++) {
            List<int> tmp = new List<int>();
            for (int j = 0; i + j < n; j++) {
                tmp.Add(grid[i + j][j]);
            }
            tmp.Sort((a, b) => b.CompareTo(a));
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = tmp[j];
            }
        }

        for (int j = 1; j < n; j++) {
            List<int> tmp = new List<int>();
            for (int i = 0; j + i < n; i++) {
                tmp.Add(grid[i][j + i]);
            }
            tmp.Sort();
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];
            }
        }

        return grid;
    }
}