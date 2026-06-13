class Solution {
public:
    int trap(vector<int>& height) {
        //optimal solution by using prefix max ans suffix max
        //so simple for calculating trapping rainwater
        int n=height.size();
        int total =0;
        vector<int>leftmax(n);
        vector<int>rightmax(n);
        
        leftmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            leftmax[i]=max(height[i],leftmax[i-1]);
        }
        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]=max(height[i],rightmax[i+1]);// little logic fault everything is right
        }
         for(int i=0;i<n;i++)
        {
            if(height[i]<leftmax[i] && height[i]<rightmax[i])
            {
                total+=min(leftmax[i],rightmax[i])-height[i];
            }
        }
   return total; }

};