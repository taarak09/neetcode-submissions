class Solution {
public:
    int trap(vector<int>& height) {
         //two pointer approach is the best approach here to use 
         vector<int>rightmax(height.size());
         vector<int>leftmax(height.size());
         leftmax[0]=height[0];
         rightmax[height.size()-1]=height[height.size()-1];
         for(int i=1;i<height.size();i++)
         {
            leftmax[i]=max(height[i],leftmax[i-1]);
         }
         int sol=0;
         for(int i=height.size()-2;i>=0;i--)
         {
            rightmax[i]=max(height[i],rightmax[i+1]);
         }
         for(int i=0;i<height.size();i++)
         {
            if(height[i]<=rightmax[i] && height[i]<=leftmax[i])
            {
               sol+=min(rightmax[i],leftmax[i])-height[i];
            }
         }
   return sol; }
};
