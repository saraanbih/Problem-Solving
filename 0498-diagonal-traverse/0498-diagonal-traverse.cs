public class Solution
{
    public int[] FindDiagonalOrder(int[][] matrix)
    {
        // Check for empty matrices
        if (matrix == null || matrix.Length == 0)
        {
            return new int[0];
        }

        // Variables to track the size of the matrix
        int N = matrix.Length;
        int M = matrix[0].Length;

        int row = 0, column = 0;
        int direction = 1;

        // The final result array
        int[] result = new int[N * M];
        int r = 0;

        // The while loop which will help us iterate over all
        // the elements in the array.
        while (row < N && column < M)
        {
            // Add the current element to result
            result[r++] = matrix[row][column];

            // Move along in the current diagonal depending on direction
            int newRow = row + (direction == 1 ? -1 : 1);
            int newColumn = column + (direction == 1 ? 1 : -1);

            // Check if the next element is within bounds
            if (newRow < 0 || newRow == N || newColumn < 0 || newColumn == M)
            {
                if (direction == 1)
                {
                    // Going upwards
                    row += (column == M - 1 ? 1 : 0);
                    column += (column < M - 1 ? 1 : 0);
                }
                else
                {
                    // Going downwards
                    column += (row == N - 1 ? 1 : 0);
                    row += (row < N - 1 ? 1 : 0);
                }

                // Flip direction
                direction = 1 - direction;
            }
            else
            {
                row = newRow;
                column = newColumn;
            }
        }

        return result;
    }
}
