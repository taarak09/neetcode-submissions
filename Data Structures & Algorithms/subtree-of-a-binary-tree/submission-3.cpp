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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // a good question it is mann come on 
        queue<TreeNode * >q;
        q.push(root);
        vector<TreeNode *>y;
        while(!q.empty())
        {
            TreeNode * temp=q.front();
            q.pop();
            if(temp->val==subRoot->val)
            {
               y.push_back(temp);
               
            }
            if(temp->right && temp->left)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
            else if (temp->right && temp->left ==nullptr)
            {
                q.push(temp->right);
            }
            else if (temp->left && temp->right==nullptr)
            {
                q.push(temp->left);
            }
            else{

            }
        }
        if(y.empty())
        {
            return false;
        }
        for(int i=0;i<y.size();i++)
        {
            if( ans(subRoot,y[i]))
            {
                return true;
            }
        }
     return false;   }
        bool ans(TreeNode* subRoot,TreeNode * y)
        {
            vector<int>r1;
        vector<int>r2;
        vector<int>r3;
        vector<int>r4;
        inorder(y,r1);
        postorder(y,r2);
        inorder(subRoot,r3);
        postorder(subRoot,r4);
        
        if(r3.size()>r1.size())
        {
            return false;
        }
      for(int i=0;i<r1.size();i++)
      {
         if(r1[i]==r3[i])
         {

         }
         else{
            return false;
         }
         if(r2[i]==r4[i])
         {

         }
         else{
            return false;
         }
      }
    return true;
        }
    void inorder(TreeNode * root, vector<int>& result)
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
    void postorder(TreeNode * root,vector<int>& result)
    {
        if(root==NULL)
        {
            result.push_back(101);
            return ;
        }
        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->val);
    }
};
