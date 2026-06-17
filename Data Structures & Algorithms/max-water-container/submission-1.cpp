class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int area=INT_MIN;
       
        while(left<right)
        {
            int area1=min(heights[left],heights[right])*(abs(left-right));
            area=max(area,area1);
            if(heights[left]>=heights[right])
            {
              right--;
            }
            else{
                left++;
            }

          

           
           
        }


    return area;}
};
