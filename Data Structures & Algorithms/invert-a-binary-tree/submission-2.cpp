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
        if(root==NULL)
        {
            return NULL;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode * i=q.front();
            q.pop();
            if(i->left && i->right)
            {
               TreeNode * temp=i->left;
               i->left=i->right;
               i->right=temp;
               q.push(i->left);
               q.push(i->right);
            }
            else if(i->left && i->right==nullptr)
            {
                i->right=i->left;
                i->left=nullptr;
                q.push(i->right);
            }
            else if (i->right && i->left==nullptr)
            {
               i->left=i->right;
               i->right=nullptr;
               q.push(i->left);
            }
            else{

            }
        }
   return root; }
};
