public class Solution {
    public int MinimumScore(int[] nums, int[][] edges) {
        int n = nums.Length;
        List<List<int>> e = new List<List<int>>();
        for(int i=0;i<n;i++)
            e.Add(new List<int>());
        
        foreach(var v in edges){
            e[v[0]].Add(v[1]);
            e[v[1]].Add(v[0]);
        }

        int sum = 0;
        foreach(int x in nums)sum^=x;

        int res = int.MaxValue;
        Func<int,int,int> dfs = null;
        Func<int,int,int,int,int> dfs2 = null;

        dfs2 = (x,f,oth,anc) => {
            int son = nums[x];
            foreach(int y in e[x]){
                if(y == f)continue;
                son ^= dfs2(y,x,oth,anc);
            }
            if(f == anc)return son;
            res = Math.Min(res,Calc(oth,son,sum^oth^son));
            return son;
        };

        dfs = (x,f) => {
            int son = nums[x];
            foreach(int y in e[x]){
                if(y == f)continue;
                son ^= dfs(y,x);
            }
            foreach(int y in e[x]){
                if(y==f)dfs2(y,x,son,x);
            }
            return son;
        };
        dfs(0,-1);
        return res;
    }
    public int Calc(int p1,int p2,int p3){
        return Math.Max(p1,Math.Max(p2,p3)) - 
               Math.Min(p1,Math.Min(p2,p3));
    }
}