public class Solution {
    public int AreaOfMaxDiagonal(int[][] d) {
        if(d == null || d.Length == 0)return 0;
        long area = -1;
        int idx = 0;
        long dig = -1;
        for(int i=0;i<d.Length;i++){
            long a = d[i][0];
            long b = d[i][1];
            long dig2 = a * a + b * b;
            long area2 = a*b;

            if(dig2 > dig || (dig2 == dig && area2 > area)){
                dig = dig2;
                area = area2;
                idx = i;
            }
        }
        return (int)((long)d[idx][0]*d[idx][1]);
    }
}