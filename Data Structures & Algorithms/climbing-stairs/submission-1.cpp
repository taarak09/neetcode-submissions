class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp1(n+1,0);
        return dp(n,dp1);
    }
    int dp(int index,vector<int> & dp1)
    {
        if(index==0)
        {
            return 1;
        }
        if(index<0)
        {
            return 0;
        }
        int u;
        int g;
        if(index-2>=0 && dp1[index-2]!=0){
           u=dp1[index-2];
        }else{
        u=dp(index-2,dp1);}
        if(index-1>=0 && dp1[index-1]!=0)
        {
           g=dp1[index-1];
        }else{
         g=dp(index-1,dp1);
        }
       dp1[index]=u+g;
        return dp1[index];

    }
};
