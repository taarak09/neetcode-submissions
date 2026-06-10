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
    vector<int> rightSideView(TreeNode* root) {
     
        if(root==NULL)
        {
            return {};
        }
        if(root->right == nullptr & root->left==nullptr)
        {
            return {root->val};
        }
        queue<pair<TreeNode *,int> >q;
        q.push({root,0});
       vector<pair<int,int>>temp;
        while(!q.empty())
        {
           TreeNode * y= q.front().first;
           int dist=q.front().second;
           q.pop();
           temp.push_back({dist,y->val});
           if(y->right && y->left )
           {
             
             q.push({y->left,dist+1});
            q.push ( {y->right,dist+1});

           }
           else if ( y->right && y->left ==nullptr)
           {
            q.push({y->right,dist+1});
            
           }
           else if( y->left && y->right==nullptr)
           {
            q.push({y->left,dist+1});
           
           }

        }
        vector<vector<int>>result(temp[temp.size()-1].first +1);
        for(int i=0;i<temp.size();i++)
        {
            result[temp[i].first].push_back(temp[i].second);
        }
        vector<int>final;
        for(int i=0;i<result.size();i++)
        {
            final.push_back(result[i][result[i].size()-1]);
        }
return final; }
};
