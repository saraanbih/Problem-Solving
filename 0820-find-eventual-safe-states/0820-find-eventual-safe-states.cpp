class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n, 0);

        // نعكس الأسهم ونحسب لكل نود كام سهم طالع منها
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
                outDegree[u]++;
            }
        }

        // نحط الهادية (اللي مش بتشاور على حد) في Stack
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (outDegree[i] == 0) {
                stk.push(i);
            }
        }

        vector<bool> safe(n, false);

        // نمشي وحدة وحدة في Stack
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            safe[node] = true;

            for (int neighbor : reverseGraph[node]) {
                outDegree[neighbor]--;
                if (outDegree[neighbor] == 0) {
                    stk.push(neighbor);
                }
            }
        }

        // نرجع اللي طلعوا آمنين
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
