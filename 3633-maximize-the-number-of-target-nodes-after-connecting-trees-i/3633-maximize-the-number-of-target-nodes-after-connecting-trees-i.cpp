class Solution {
public:
    int dfs(int node,int parent,vector<vector<int>> &adj,int k){
        if(k<0)return 0;
        int res = 1;
        for(auto&ne : adj[node]){
            if(ne == parent)continue;
            res += dfs(ne,node,adj,k-1);
        }
        return res;
    }
    vector<int> build(vector<vector<int>> &edges,int k){
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto &ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        vector<int> res(n);
        for(int i=0;i<n;i++)
            res[i] = dfs(i,-1,adj,k);
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1,m=edges2.size()+1;
        vector<int> cnt1 = build(edges1,k);
        vector<int> cnt2 = build(edges2,k-1);
        int mx_cnt = *max_element(cnt2.begin(),cnt2.end());
        vector<int> res(n);
        for(int i = 0;i<n;i++){
            res[i] = mx_cnt + cnt1[i];
        }
        return res;

    }
};