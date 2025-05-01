/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        unordered_map<Node*,Node*> clone;
        Node*copy = new Node(node->val);
        clone[node] = copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node *cur = q.front();
            q.pop();
            for(auto &n : cur->neighbors){
                if(clone.find(n) == clone.end()){
                    clone[n] = new Node(n->val);
                    q.push(n);
                }
                clone[cur]->neighbors.push_back(clone[n]);
            }
        }   
        return copy;
    }
};