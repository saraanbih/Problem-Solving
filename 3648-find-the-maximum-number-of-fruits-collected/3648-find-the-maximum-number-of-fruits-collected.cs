public class Solution {
    public int MaxCollectedFruits(int[][] fruits) {
        int n = fruits.Length;
        int ans = 0;
        for(int i=0;i<n;i++)ans+=fruits[i][i];

        int dp(){
            int[] mx = Enumerable.Repeat(int.MinValue,n).ToArray();
            int[] cur = new int[n];
            mx[n-1] = fruits[0][n-1];

            for(int i = 1;i<n-1;i++){
                Array.Fill(cur,int.MinValue);
                for(int j = Math.Max(n-1-i,i+1);j<n;j++){
                    int var = mx[j];
                    if(j - 1 >= 0)var = Math.Max(var,mx[j-1]);
                    if(j+1 < n)var = Math.Max(var,mx[j+1]);
                    cur[j] = var + fruits[i][j]; 
                }
                var tmp = mx;
                mx = cur;
                cur = tmp;
            }
            return mx[n-1];
        }
        ans += dp();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                var temp = fruits[j][i];
                fruits[j][i] = fruits[i][j];
                fruits[i][j] = temp;
            }
        }
        ans += dp();
        return ans;
    }
}