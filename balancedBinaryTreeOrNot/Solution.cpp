**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, bool& test)
    {
        if(root == nullptr)
            return 0;

        int lheight = height(root->left, test);
        int rheight = height(root->right, test);

        if(abs(lheight - rheight) > 1)
            test = false;

        return max(lheight, rheight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool test = true;
        if(root == nullptr)
            return true;
        int temp = height(root, test);
        return test;
        if(temp == -1)
            return false;
        else
            return true;
            //return (isBalanced(root->left) && isBalanced(root->right));
    }
};
