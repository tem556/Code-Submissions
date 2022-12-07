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
    // Use DFS to clone the graph
    unordered_map<int, Node*> um;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) 
            return nullptr;

        int val = node -> val;
        if (um[val] != nullptr)
            return  um[val];

        vector<Node*> neighbors = node -> neighbors;
        Node* current = new Node(node -> val);
        um[val] = current;

        for (Node* &n: neighbors) {
            Node* newNode = cloneGraph(n);
            (current -> neighbors).push_back(newNode);
        }

        return current;
    }
};
