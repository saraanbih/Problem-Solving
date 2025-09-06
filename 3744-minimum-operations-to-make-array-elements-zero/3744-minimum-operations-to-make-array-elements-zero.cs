public class Solution {
    private long Get(int num) {
        long cnt = 0;
        int i = 1;
        int baseVal = 1;

        while (baseVal <= num) {
            int end = Math.Min(baseVal * 2 - 1, num);
            cnt += (long)((i + 1) / 2) * (end - baseVal + 1);
            i++;
            baseVal *= 2;
        }
        return cnt;
    }

    public long MinOperations(int[][] queries) {
        long res = 0;
        foreach (var q in queries) {
            long count1 = Get(q[1]);
            long count2 = Get(q[0] - 1);
            res += (count1 - count2 + 1) / 2;
        }
        return res;
    }
}