class Solution {
public:
   vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int , vector<int>> adj;
    for(auto & pair : adjacentPairs){
        int u = pair[0],v=pair[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int st = 0;
    for(auto&[k,n] : adj){
        if(n.size() == 1){
            st = k;
            break;
        }
    }
    int n = adjacentPairs.size() + 1;
    unordered_set<int> vis;
    vector<int> res(n);
    res[0] = st;
    vis.insert(st);
    for(int i=1;i<n;i++){
        for(int ne : adj[res[i-1]]){
            if(!vis.count(ne)){
                res[i] = ne;
                vis.insert(ne);
                break;
            }
        }
    }
    return res;
}
};
