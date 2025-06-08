class Solution {
public:
    void dfs(long long st,vector<int> &arr,int n){
        if(st > n)return;
        arr.push_back(st);
        for(int i=0;i<=9;i++){
            int nxt = (st*10LL) + i;
            if(nxt<=n)dfs(nxt,arr,n);
            else break;
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
            dfs(i,ans,n);
        return ans;
    }
};