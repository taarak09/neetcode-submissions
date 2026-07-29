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
        queue<pair<int,TreeNode*>>q;
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>>final;
        vector<pair<int,int>>result;
        q.push({0,root});
        while(!q.empty())
        {
            TreeNode* g=q.front().second;
            int d=q.front().first;

            q.pop();
            result.push_back({d,g->val});
            if(g->right && g->left)
            {
                q.push({d+1,g->left});
                q.push({d+1,g->right});
            }
            else if(g->right && g->left==nullptr)
            {
                q.push({d+1,g->right});
            }
            else if (g->left && g->right==nullptr)
            {
                q.push({d+1,g->left});
            }
            else{

            }
        }
        int size=result[result.size()-1].first;
        size+=1;
        final.resize(size);
        for(int i=0;i<result.size();i++)
        {
            final[result[i].first].push_back(result[i].second);
        }
        result.clear();
        vector<int>r1;
        for(int i=0;i<final.size();i++)
        {
             r1.push_back(final[i][final[i].size()-1]);
        }


   return r1; }
};
