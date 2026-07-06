class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp1(m, vector<int>(n,-1));
        // we are doing memoization here man 
      return dp(dp1,m-1,n-1);

    }
    int dp( vector<vector<int>> & dp1,int m ,int n )
    {
        
        if(m==0 && n==0)
        {
           return 1;
        }
       
        int way1=0;
        int way2=0;
        if(m-1>=0 && n>=0){
            if(dp1[m-1][n]!=-1)
            {
                way1=dp1[m-1][n];
            }else{
        way1=dp(dp1,m-1,n);}
        }
        if(m>=0 && n-1>=0){
            if(dp1[m][n-1]!=-1)
            {
                way2=dp1[m][n-1];
            }else{
        way2=dp(dp1,m,n-1);
            }
        
        }
        int ans=way1+way2;
        dp1[m][n]=ans;
        return ans;

    }
};
