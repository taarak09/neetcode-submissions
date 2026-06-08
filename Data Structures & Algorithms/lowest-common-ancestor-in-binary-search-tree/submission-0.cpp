/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //revision sessin
        //recursion me sab cover ho jata hai no need for extra edge cases
       
  return traversal(root,p,q);
        
    }
    TreeNode *  traversal(TreeNode * root,TreeNode* p,TreeNode * q)
    {
        if(root==NULL || root==p ||root==q)
        {
            return root;
        }
        TreeNode * left=traversal(root->left,p,q);
        TreeNode * right=traversal(root->right,p,q);
        if(left==NULL)
        {
            return right;
        }
        else if (right==NULL )
        {
            return left;
        }
        else{
            return root;
        }



    }
};