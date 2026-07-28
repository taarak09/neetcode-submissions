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
        //this is somewhat a different question your O(n) level traversal will work here man 
     int flag=0;
     diameter(root,flag);
     if(flag==1)
     {
        return false;
     }

   return true; }
    int diameter(TreeNode * root,int & flag)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=diameter(root->left,flag);
        int rh=diameter(root->right,flag);
        if(abs(lh-rh)>1)
        {
           flag=1;
        }
        
        return 1+max(lh,rh);

    }
};
