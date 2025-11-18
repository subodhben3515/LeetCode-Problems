/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    /*
    guard check
    BFS approach
    queue of Node
    Till q.empty
    add node
    get front
    pop
    add next nodes to q
    add curr node to final op list

    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            vector<int> currLevel;
            int level = q.size();

            for (int i = 0; i < level; i++) 
            {
                auto currNode = q.front();
                q.pop();

                if (currNode->left != nullptr) 
                    q.push(currNode->left);

                if (currNode->right != nullptr)
                    q.push(currNode->right);

                currLevel.push_back(currNode->val);
            }
            result.push_back(currLevel);
        }
        return result;
    }
};
