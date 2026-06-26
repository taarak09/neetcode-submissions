class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       
       vector<vector<int>>dp1(coins.size(),vector<int>(amount+1,-1));
       int y=dp(coins,amount,coins.size()-1,dp1);
       if(y==1e9)
       {
        return -1;
       }
        //to optimize my memoization method yes!!!!!!
        //god question man yes!!!!

  return y;  }
    int dp(vector<int>& coins, int amount,int index, vector<vector<int>>&dp1)
    {
        if(index==0)
        {
            if(amount%coins[0]==0)
            {
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(amount==0)
        {
            return 0;
        }
       
        int take=1e9;
        int non_take=1e9;
        if(amount-coins[index]>=0){
        if(dp1[index][amount-coins[index]]!=-1)
        {
          take=1+dp1[index][amount-coins[index]];
        }else{
        take=1+dp(coins,(amount-coins[index]),index,dp1);}}
        if(index-1>=0){
            if(dp1[index-1][amount]!=-1){
                non_take=dp1[index-1][amount];
            }else{
        non_take=0+dp(coins,amount,index-1,dp1);}}
        dp1[index][amount]=min(take,non_take);
  return dp1[index][amount] ;
      







    }
};
