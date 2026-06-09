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
    bool isBalanced(TreeNode* root) {
        int diff=INT_MIN;
       diameter( root, diff);
        if ( diff==INT_MIN)
        {
            return true;
        }
        if(diff>1)
        {
            return false;
        }

    return true;}
    int diameter(TreeNode * root,int & diff)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh= diameter(root->left,diff);
        int rh=diameter(root->right,diff);
        diff=max(diff,abs(lh-rh));
  return 1+max(lh,rh);
    }
};
