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
    bool isValidBST(TreeNode* root) {
        vector<int>result;
        inorder(root,result);
        unordered_map<int,int>mpp;
        for(int i:result)
        {
            mpp[i]++;
        }
        if(mpp.size()!=result.size())
        {
            return false;
        }
        if(is_sorted(result.begin(),result.end()))
        {
            return true;
        }
 return false;   }
    void inorder(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
};
