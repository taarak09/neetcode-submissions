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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return ans(root,target);
    }
    TreeNode* ans(TreeNode * root,int target)
    {
        if(root==NULL)
        {
            return NULL;
        }
        root->left=ans(root->left,target);
        root->right=ans(root->right,target);
        if(root->left==nullptr && root->right==nullptr && root->val==target)
        {
          return NULL;
        }
        return root;
    }
};