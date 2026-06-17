class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //good question
        int ans=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                ans=max(ans,(prices[j]-prices[i]));
            }
        }

if(ans<0)
{
    return 0;
}

    return ans;}
};
