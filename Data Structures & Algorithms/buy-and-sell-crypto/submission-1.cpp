class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)
        {
            return 0;
        }
        vector<int>rightmax(prices.size());
        rightmax[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--)
        {
          rightmax[i]=max(prices[i],rightmax[i+1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
          ans=max(ans,(rightmax[i]-prices[i]));
        }
       
  return ans;  }
};
