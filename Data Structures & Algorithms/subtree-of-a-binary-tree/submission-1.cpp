class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // good question
        if(root==NULL && subRoot!=NULL)
        {
            return false;
        }
        if(root==NULL  && subRoot==NULL)
        {
            return true;
        }
        vector<TreeNode *>arr;
        queue<TreeNode* >q;
        q.push(root);
        TreeNode * carrier=NULL;
        while(!q.empty())
        {
            TreeNode* tr= q.front();
            q.pop();
            if(tr->val == subRoot->val)
            {
              arr.push_back(tr);
             
            }
            if(tr->right && tr->left)
            {
                q.push(tr->right);
                q.push(tr->left);
            }
            else if ( tr->right && tr->left ==nullptr)
            {
                q.push(tr->right);
            }
            else if( tr->left && tr->right ==nullptr)
            {
                q.push(tr->left);
            }
        }
        if(arr.empty())
        {
            return false;
        }
      vector<int>ori;
      vector<int>dup;
      for(int i=0;i<arr.size();i++)
      {
        TreeNode * u= arr[i];
        inorder(u,ori);
        postorder(u,ori);
        inorder(subRoot,dup);
        postorder(subRoot,dup);
        if(ori==dup)
        {
            return true;
        }
        ori.clear();
        dup.clear();
      }

    return false; }
        void inorder(TreeNode * root, vector<int>& nums)
    {
        if ( root==NULL)
        {
            nums.push_back(101);
            return;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    void postorder(TreeNode * root, vector<int>& nums)
    {
         if ( root==NULL)
        {
            nums.push_back(101);
            return;
        }
       postorder(root->left,nums);
       postorder(root->right,nums);
         nums.push_back(root->val);
    } 

};