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
        // optimized algorithm for finding lowest common ancestor for a binary search tree
        return traversal(root,p,q);
    }
    TreeNode * traversal(TreeNode * root,TreeNode * p,TreeNode *q)
    {
        if(root==NULL)
        {
            return NULL;
        }
         int current=root->val;
         if(current<p->val && current<q->val)
         {
            return traversal(root->right,p,q);
         }
         else if (current>p->val && current>q->val)
         {
            return traversal(root->left,p,q);

         }
         else{
            return root;
         }





    }
};
