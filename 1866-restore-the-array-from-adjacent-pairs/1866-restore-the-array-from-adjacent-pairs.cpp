class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        // 1. بناء الخريطة
        for (auto& pair : adjacentPairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // 2. إيجاد البداية: عنصر له جار واحد فقط
        int start = 0;
        for (auto& [key, neighbors] : graph) {
            if (neighbors.size() == 1) {
                start = key;
                break;
            }
        }

        // 3. بناء المصفوفة
        int n = adjacentPairs.size() + 1;
        vector<int> result(n);
        unordered_set<int> visited;

        result[0] = start;
        visited.insert(start);

        for (int i = 1; i < n; ++i) {
            for (int neighbor : graph[result[i - 1]]) {
                if (!visited.count(neighbor)) {
                    result[i] = neighbor;
                    visited.insert(neighbor);
                    break;
                }
            }
        }

        return result;
    }
};
