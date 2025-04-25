class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1) return false; // لقينا loop
        if (state[node] == 2) return true;  // نود آمنة خلاص

        state[node] = 1; // بنبدأ نزور

        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, state)) {
                return false; // لو أي neighbor مش آمن → إحنا كمان مش آمنين
            }
        }

        state[node] = 2; // خلصنا وكل حاجة تمام → آمنين
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0 = unknown, 1 = visiting, 2 = safe
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, state)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
