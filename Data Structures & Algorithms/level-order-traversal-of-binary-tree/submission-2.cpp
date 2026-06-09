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
        //new method invented by you and this is correct and always use this method while solving in real interview OA
        if(root==NULL)
        {
            return {};
        }
        queue<pair<int,TreeNode *>>q;
        vector<pair<int,int>>temp1;
        q.push({0,root});
        while(!q.empty())
        {
            TreeNode * temp=q.front().second;
            int r=temp->val;
            int dist=q.front().first;
            q.pop();
            temp1.push_back({dist,r});
            if(temp->right && temp->left)
            {
                q.push({dist+1,temp->left});
                q.push({dist+1,temp->right});
            }
            else if( temp->right && temp->left==nullptr)
            {
                q.push({dist+1,temp->right});

            }
            else if ( temp->left && temp->right==nullptr)
            {
                q.push({dist+1,temp->left});
            }

        }
        //segregation begins here
  
  int size=temp1[temp1.size()-1].first +1 ;
    vector<vector<int>>result(size);
    for(int i=0;i<temp1.size();i++)
    {
        result[temp1[i].first].push_back(temp1[i].second);
    }
 return  result;   }
};
