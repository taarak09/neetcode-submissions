class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp1(cost.size()+1,-1);
       
      return   dp(cost,dp1,cost.size());
    }
    int dp(vector<int>& cost,vector<int>& dp1,int index )
    {
        //same as staircase but only here is cost of each step in this question
        if(index==0)
        {
            return 0;
        }
        if(index<0)
        {
           return 1e9; 
        }
        int u=1e9;
        int g=1e9;
        if(index-2>=0){
           if(dp1[index-2]!=-1)
           {
             u=dp1[index-2]+cost[index-2];
           }else{
         u= dp(cost,dp1,index-2)+cost[index-2];}}
         else{
            u=0;
         }
        if(index-1>=0){
            if(dp1[index-1]!=-1)
            {
                g=dp1[index-1]+cost[index-1];
            }else{
         g=dp(cost,dp1,index-1)+cost[index-1];}}
         else{
            g=0;
         }
        dp1[index]=min(u,g);
        return dp1[index];


    }

};
