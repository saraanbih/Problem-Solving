public class Solution
{
    public int MaxTotalFruits(int[][] fruits, int startPos, int k)
    {
        int n = fruits.Length;
        int[] sum = new int[n + 1];
        int[] indices = new int[n];
        sum[0] = 0;

        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }

        int ans = 0;

        for (int x = 0; x <= k / 2; x++)
        {
            // move left x steps, then move right k - 2x steps
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = LowerBound(indices, 0, n - 1, left);
            int end = UpperBound(indices, 0, n - 1, right);
            ans = Math.Max(ans, sum[end] - sum[start]);

            // move right x steps, then move left k - 2x steps
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = LowerBound(indices, 0, n - 1, left);
            end = UpperBound(indices, 0, n - 1, right);
            ans = Math.Max(ans, sum[end] - sum[start]);
        }

        return ans;
    }

    public int LowerBound(int[] arr, int left, int right, int val)
    {
        int res = right + 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= val)
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }

    public int UpperBound(int[] arr, int left, int right, int val)
    {
        int res = right + 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] > val)
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
}
