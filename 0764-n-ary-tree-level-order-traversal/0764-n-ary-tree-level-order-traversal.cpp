/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {}; // Directly return if root is nullptr.

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            for (int i = q.size(); i > 0; i--) { // Use the queue size directly.
                Node* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                for (Node* child : curr->children) { // Use range-based for for readability.
                    q.push(child);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
