class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n, 0);

        // 1. بناء الجراف العكسي وحساب out-degree
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u); // عكسنا الاتجاه
                outDegree[u]++;
            }
        }

        // 2. Queue للبداية من النودز اللي out-degree = 0 (terminal nodes)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n, false);

        // 3. طوبولوجيكل سورْت
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int neighbor : reverseGraph[node]) {
                outDegree[neighbor]--;
                if (outDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. بناء الناتج
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
