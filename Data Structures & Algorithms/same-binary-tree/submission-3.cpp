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
        //inorder and postorder together can tell if trees are same or not
        vector<int>r;
        vector<int>r1;
        vector<int>r2;
        vector<int>r3;
        inorder(p,r);
        preorder(p,r1);
        inorder(q,r2);
        preorder(q,r3);
        if(r==r2 && r3==r1)
        {
            return true;
        }
        
   return false; }
    void inorder(TreeNode * root,vector<int>& result)
    {
        if(root==NULL)
        {
            result.push_back(101);
            return ;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
    void preorder(TreeNode * root,vector<int>& result)
    {
        if(root==NULL)
        {
            result.push_back(101);
            return ;
        }
        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
        
    }

};
