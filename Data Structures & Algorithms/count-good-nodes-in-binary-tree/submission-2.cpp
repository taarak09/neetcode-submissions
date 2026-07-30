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
        //counting good nodes in binary tree
        queue<pair<TreeNode*,vector<int>>>q;
        int ans=1;
        q.push({root,{}});
        while(!q.empty())
        {
            TreeNode * i=q.front().first;
            vector<int> j=q.front().second;
            if(!j.empty()){
            sort(j.begin(),j.end());
            if(j[j.size()-1]<=i->val)
            {
                ans+=1;
            }}
            q.pop();
            j.push_back(i->val);
            if(i->right && i->left)
            {
                q.push({i->left,j});
                q.push({i->right,j});
            }
            else if(i->right && i->left ==nullptr)
            {
                q.push({i->right,j});
            }
            else if (i->left && i->right==nullptr)
            {
                q.push({i->left,j});
            }
            else{

            }



        }


   return ans; }
};
