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
        //let's do it by recursion dfs
        if(root==NULL)
        {
            return NULL;
        }
        if(root->right==nullptr && root->left == nullptr)
        {
            return root;
        }
         reverse(root);
        return root;
    }
    void reverse(TreeNode * root)
    {
        if(root->right==nullptr && root->left ==nullptr)
        {
           return;
        }
        
        if(root->right && root->left)
        {
            TreeNode * temp= root->right;
            root->right=root->left;
            root->left=temp;
            reverse(root->right);
            reverse(root->left);

        }
        else if ( root->right && root->left==nullptr)
        {
            root->left=root->right;
            root->right=nullptr;
            reverse(root->left);
        }
        else if ( root->left && root->right == nullptr)
        {
            root->right=root->left;
            root->left=nullptr;
            reverse(root->right);
        }




    }
};
