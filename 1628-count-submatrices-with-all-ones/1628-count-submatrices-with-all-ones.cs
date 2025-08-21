public class Solution {
    public int NumSubmat(int[][] mat) {
        int n = mat[0].Length;
        int[] heights = new int[n];
        int res = 0;
        foreach (var row in mat) {
            for (int i = 0; i < n; i++) {
                heights[i] = row[i] == 0 ? 0 : heights[i] + 1;
            }
            var stack = new Stack<int[]>();
            stack.Push(new int[] { -1, 0, -1 });
            for (int i = 0; i < n; i++) {
                int h = heights[i];
                while (stack.Peek()[2] >= h) {
                    stack.Pop();
                }
                var top = stack.Peek();
                int j = top[0];
                int prev = top[1];
                int cur = prev + (i - j) * h;
                stack.Push(new int[] { i, cur, h });
                res += cur;
            }
        }
        return res;
    }
}