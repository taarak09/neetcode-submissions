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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return manufacture(preorder,inorder,mpp,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode * manufacture(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& mpp, int prestart,int preend,int instart,int inend)
    {
      if(prestart>preend || instart>inend)
      {
        return NULL;
      }
      TreeNode * temp= new TreeNode(preorder[prestart]);
      int inroot= mpp[temp->val];
      int  numsleft=inroot-instart;
      temp->left=manufacture(preorder,inorder,mpp,prestart+1,prestart+numsleft,instart,inroot-1);
      temp->right=manufacture(preorder,inorder,mpp,prestart+numsleft+1,preend,inroot+1,inend);

   return temp; }
};
