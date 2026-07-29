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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<pair<int,int>>result;
        if(root==NULL)
        {
            return {};
        }
        queue<pair<int,TreeNode *>>q;
        q.push({0,root});
        while(!q.empty())
        {
            int y=q.front().first;
            TreeNode * u=q.front().second;
            result.push_back({y,u->val});
            q.pop();
            if(u->right && u->left)
            {
                q.push({y+1,u->left});
                q.push({y+1,u->right});
            }
            else if (u-> right && u->left==nullptr)
            {
                q.push({y+1,u->right});
            }
            else if(u->left && u->right==nullptr)
            {
                q.push({y+1,u->left});
            }
            else{

            }
        }

        vector<vector<int>>final(result.size());
        for(int i=0;i<result.size();i++)
        {
            final[result[i].first].push_back(result[i].second);
        }
        int index=-1;
    for(int i=0;i<final.size();i++)
    {
        if(final[i].empty())
        {
          index=i;
          break;
        }
    }
    if(index==-1)
    {
        return final;
    }
    else{
        while(final[index].empty())
        {
            final.erase(final.begin()+index);
            if(index==final.size())
            {
                break;
            }
        }
    }
       

  return final;  }
};
