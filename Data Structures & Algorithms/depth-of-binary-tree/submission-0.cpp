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
        // i can do this by bfs easily
        if(root==NULL)
        {
            return 0;
        }
        if(root->right == nullptr && root->left ==nullptr)
        {
            return 1;
        }
        queue<pair<TreeNode * ,int>> q;
        q.push({root,0});
        int ans=INT_MIN;
        while(!q.empty())
        {
          TreeNode * temp = q.front().first;
          int dist=q.front().second;
         ans=max(ans,dist);
         q.pop();
         if(temp->right && temp->left)
         {
            q.push({temp->right,dist+1});
            q.push({temp->left,dist+1});
         }
         else if ( temp->right && temp->left ==nullptr)
         {
            q.push({temp->right,dist+1});
         }
         else if (temp->left && temp->right==nullptr)
         {
            q.push({temp->left,dist+1});
         }


        }
   return ++ans; }
};
