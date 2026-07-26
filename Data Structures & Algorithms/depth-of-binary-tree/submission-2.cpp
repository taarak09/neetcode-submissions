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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode *,int>>q;
        if(root==NULL)
        {
         return 0;
        }
        int ans=0;
        q.push({root,1});
        while(!q.empty())
        {
         TreeNode * y=q.front().first;
         int depth=q.front().second;
         ans=max(ans,depth);
         q.pop();
         if(y->left && y->right)
         {
            q.push({y->left,depth+1});
            q.push({y->right,depth+1});
         }
         else if (y->left && y->right==nullptr)
         {
            q.push({y->left,depth+1});
         }
         else if(y->right && y->left==nullptr)
         {
            q.push({y->right,depth+1});
         }
         else{

         }






        }

  return ans;  }
};
