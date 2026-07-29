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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
    TreeNode * lca(TreeNode* root,TreeNode* p,TreeNode * q)
    {
       // recursive way to find the lowest common ancestor
       if(root==NULL || root==p ||root==q)
       {
        return root;
       }
       TreeNode * left=lca(root->left,p,q);
       TreeNode* right=lca(root->right,p,q);
       if(left==NULL)
       {
        return right;
       }
       else if(right==NULL)
       {
        return left;
       }
       else{
        return root;
       }

    }
};
