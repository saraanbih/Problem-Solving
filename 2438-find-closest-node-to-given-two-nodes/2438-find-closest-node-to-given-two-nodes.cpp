class Solution {
public:
    void dfs(int node,vector<int>&adj,vector<bool>&vis,vector<int> &dist){
        vis[node] = true;
        int n = adj[node];
            if(n!= -1 && !vis[n]){
                dist[n] = 1 + dist[node];
                dfs(n,adj,vis,dist); 
            }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2){
        int n = edges.size();
        vector<bool> vis1(n,false),vis2(n,false);
        vector<int> dist1(n,numeric_limits<int>::max()),dist2(n,numeric_limits<int>::max());
        dist1[node1] = 0,dist2[node2] = 0;
        dfs(node1,edges,vis1,dist1);
        dfs(node2,edges,vis2,dist2);
        int min_node = -1,min_now = INT_MAX;
        for(int cur = 0;cur<n;cur++){
            if(min_now > max(dist1[cur],dist2[cur])){
                min_node = cur;
                min_now =  max(dist1[cur],dist2[cur]);
            }
        }
        return min_node;
    }
};