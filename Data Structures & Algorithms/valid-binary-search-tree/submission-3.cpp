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
        //if you can perform binary search then it is a valid binary search tree
          if(root==NULL)
        {
            return true;
        }
        if(root->right==nullptr && root->left==nullptr)
        {
            return true;
        }
     vector<int>temp;
     inorder(root,temp);
     vector<int>te=temp;
     set<int>se(te.begin(),te.end());
        if(is_sorted(temp.begin(),temp.end()) && se.size()==temp.size())
        {
            return true;
        }
     
     
     
  return false;  }
    void inorder(TreeNode * root,vector<int>& nums)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    
};
