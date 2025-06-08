public class Solution {
    public void dfs(int st,IList<int> ans,int n){
        if(st>n)return;
        ans.Add(st);
        for(int i=0;i<=9;i++){
            int nxt = st * 10 + i;
            if(nxt<=n)dfs(nxt,ans,n);
        }
    }
    public IList<int> LexicalOrder(int n) {
        IList<int> ans = new List<int>();
        for(int i=1;i<=9;i++)
            dfs(i,ans,n);
        return ans;
    }
}