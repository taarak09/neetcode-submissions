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

class matrix{
public:
TreeNode *  a;
int dist;
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
       if(root->right==nullptr && root->left==nullptr)
       {
        return true;
       }
      queue<TreeNode * >q;
      q.push({root});
      while(!q.empty())
      {
        TreeNode * temp=q.front();
        q.pop();
        if(temp->right && temp->left)
        {
            int e=height(temp->right);
            int u=height(temp->left);
            if(abs(e-u)>1)
            {
                return false;
            }
            q.push(temp->right);
            q.push(temp->left);
        }
        else if (temp->right && temp->left ==nullptr)
        {
            int o=height(temp->right);
            if ( abs (o-0)>1)
            {
                return false;
            }
            q.push(temp->right);
        }
        else if ( temp->left && temp->right==nullptr)
        {
            int o=height(temp->left);
            if(abs(o)>1)
            {
                return false;
            }
            q.push(temp->left);
        }
        else{

        }
      }
     
     
   return true;   }
  
    int height(TreeNode * root)
    {
        queue<matrix>q;
        int ans=INT_MIN;
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode * t= q.front().a;
            int d1= q.front().dist;
            ans=max(ans,d1);
            q.pop();
            if(t->right && t->left)
            {
                q.push({t->right,d1+1});
                 q.push({t->left,d1+1});

            }
            else if(t->right && t->left==nullptr)
            {
               q.push({t->right,d1+1});
            }
            else if ( t->right==nullptr && t->left)
            {
                q.push({t->left,d1+1});
            }

        }
        return ans+1;
    }
};
