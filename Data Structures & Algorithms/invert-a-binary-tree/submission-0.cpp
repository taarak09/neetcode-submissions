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
        //first we will try bfs if not the we will try dfs
        if(root==NULL)
        {
            return NULL;
        }
        if(root->left==nullptr && root->right==nullptr)
        {
            return root;
        }

        queue<TreeNode * > q;
        q.push(root);
        //no need for visited here
        while(!q.empty())
        {
            TreeNode * u = q.front();
            int g= q.front()->val;
            q.pop();
            if(u->right && u ->left)
            {
                TreeNode * temp=u->right;
              u->right=u->left;
              u->left=temp;
              q.push(u->right);
              q.push(u->left);


            }
           else if(u->right && u->left==nullptr)
           {
             u->left=u->right;
             u->right=nullptr;
             q.push(u->left);

           }
           else if (u->left && u->right==nullptr){
               u->right=u->left;
               u->left=nullptr;
               q.push(u->right);
           }

       }
    return root; }
};
