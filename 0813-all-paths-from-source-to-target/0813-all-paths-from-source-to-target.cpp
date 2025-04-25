class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        // Add the current node to the path
        path.push_back(node);
        
        // If we've reached the last node (n-1), add the path to the result
        if (node == graph.size() - 1) {
            result.push_back(path);
        } else {
            // Visit all neighbors
            for (int neighbor : graph[node]) {
                dfs(neighbor, graph, path, result);
            }
        }
        
        // Backtrack: remove the current node from the path
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;  // To store all the paths
        vector<int> path;  // To store the current path
        dfs(0, graph, path, result);  // Start DFS from node 0
        return result;
    }
};
