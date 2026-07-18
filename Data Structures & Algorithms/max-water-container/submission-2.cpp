class Solution {
public:
    int maxArea(vector<int>& heights) {
        //two pointer approach is the best for this one
        int low=0;
        int area=0;
        int high=heights.size()-1;
        while(low<high)
        {
          area=max(area,min(heights[low],heights[high])*(high-low));
          // i need to maximize the product 
          if(heights[low]>heights[high])
          {
            high--;
          }
          else{
            low++;
          }
          


        }
        
   return area; }
};
