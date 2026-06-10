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
    int goodNodes(TreeNode* root) {
        //nice question 
        if(root==NULL)
        {
            return 0;
        }
        if(root->right==NULL && root->left ==NULL)
        {
            return 1;
        }
        vector<int>parent;
        int count=0;
        queue<pair<TreeNode * ,vector<int>>>q;
        q.push({root,{}});
        while(!q.empty())
        {
            TreeNode * i=q.front().first;
            vector<int>temp=q.front().second;
          
            if(temp.empty())
            {
                count++;
            }else{
             vector<int>t1=temp;
             sort(t1.begin(),t1.end());
             reverse(t1.begin(),t1.end());
             if(i->val>=t1[0])
             {
                count++;
             }

            }
            q.pop();
              temp.push_back(i->val);
            if(i->right && i->left )
            {
                q.push({i->left,temp});
                q.push({i->right,temp});
            }
            else if ( i->right && i->left ==nullptr)
            {
                q.push({i->right,temp});
            }
            else if ( i->left && i->right ==nullptr)
            {
                q.push({i->left,temp});
            }

        }
   return count; }
};
