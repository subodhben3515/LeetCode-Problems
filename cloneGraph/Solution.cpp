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
        unordered_map<Node*, Node*> mp;

        auto dfs = [&](this auto&& dfs, Node* currentNode) -> Node*
        {
            if(currentNode == nullptr)
                return nullptr;

            if(mp.contains(currentNode))
                return mp[currentNode];

            Node* clonedNode = new Node(currentNode->val);
            mp[currentNode] =  clonedNode;

            for(auto nList: currentNode->neighbors)
            {
                clonedNode->neighbors.push_back(dfs(nList));
            }
            return clonedNode;
        };
        return dfs(node);
    }
};
