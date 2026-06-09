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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>r1;
        vector<int>r2;
        inorder(p,r1);
        inorder(q,r2);
        postorder(p,r1);
        postorder(q,r2);
        if ( r1==r2)
        {
            return true;
        }
  return false;  }
    void inorder(TreeNode * root,vector<int>& nums)
    {
        if(root==NULL)
        {
           nums.push_back(101);
            return ;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    void postorder(TreeNode * root,vector<int>& nums)
    {
        if(root==NULL)
        {
            nums.push_back(101);
            return ;
        }
        postorder(root->left,nums);
        
        postorder(root->right,nums);
        nums.push_back(root->val);
    }
};
