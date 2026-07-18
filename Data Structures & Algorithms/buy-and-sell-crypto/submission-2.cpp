class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // come on lets start 
        //do this in only the o(n)time complexity
        vector<int>leftmax(prices.size());
        leftmax[0]=prices[0];
      
        vector<int>rightmax(prices.size());
        rightmax[prices.size()-1]=prices[prices.size()-1];
        for(int i=1;i<prices.size();i++)
        {
          leftmax[i]=min(prices[i],leftmax[i-1]);
        }
        for(int i=prices.size()-2;i>=0;i--)
        {
          rightmax[i]=max(prices[i],rightmax[i+1]);
        }
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
           ans=max(ans,(rightmax[i]-leftmax[i]));  
        }

   return ans; }
};
