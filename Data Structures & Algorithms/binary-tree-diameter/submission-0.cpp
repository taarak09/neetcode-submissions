

class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode * temp = root;
        if ( root==NULL)
        {
            return 0;
        }
        if(root->right==nullptr && root->left==nullptr)
        {
            return 0;
        }
        int maxi=INT_MIN;
        diameter(root,maxi);
        return maxi;

    }
    int diameter (TreeNode * root ,int& maxi)
      {
        if(root==NULL)
        {
            return 0;
        }

        int lh=diameter(root->left,maxi);
        int rh=diameter(root->right,maxi);
        maxi=max(lh+rh,maxi);
        return 1+max(rh,lh);

        

      }
    
};
