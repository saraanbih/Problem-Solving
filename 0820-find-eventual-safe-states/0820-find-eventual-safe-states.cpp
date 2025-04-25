class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        if (color[node] != 0)
            return color[node] == 2;  // لو لقيت node لونه أسود (2) → آمن

        color[node] = 1; // خليها رمادي → بنزورها دلوقتي

        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, color))
                return false;  // لو فيه neighbor مش آمن → أنا كمان مش آمن
        }

        color[node] = 2;  // خلصت من كل الجيران من غير مشاكل → node آمنة
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);  // كلهم لسه أبيض
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, color)) {
                result.push_back(i);  // اللي يطلع آمن، نحطه في النتيجة
            }
        }

        return result;
    }
};
