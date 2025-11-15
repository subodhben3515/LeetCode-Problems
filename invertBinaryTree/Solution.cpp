/**
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
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr)
            return root;
        
        swap(root->left,root->right);
        if(root->left != nullptr)
        {
            invertTree(root->left);
        }
        if(root->right != nullptr)
            invertTree(root->right);
        
        return root;


// Mine working but....not opimized
/*
        if(root == nullptr)
            return root;
        if(root->left == nullptr && root->right == nullptr)
            return root;
        else if(root->left != nullptr && root->right != nullptr)
        {
            invertTree(root->left);
            invertTree(root->right);
            //TreeNode* temp = nullptr;
            //temp = root->left;
            //root->left = root->right;
            //root->right = temp;
            swap(root->left, root->right);
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            invertTree(root->left);
            swap(root->left, root->right);

            TreeNode* temp = nullptr;
            temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            invertTree(root->right);
            swap(root->right, root->left);

            TreeNode* temp = nullptr;
            temp = root->right;
            root->right = root->left;
            root->left = temp;
        }

        return root;*/
    }
};
