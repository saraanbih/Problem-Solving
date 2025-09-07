public class Solution {
    public int[] SumZero(int n) {
        List<int> ans = new List<int>();
        int md = n/2;
        for(int i=-md;i<=md;i++){
            if(n%2==0 && i == 0)continue;
            ans.Add(i);
        }
        return ans.ToArray();
    }
}