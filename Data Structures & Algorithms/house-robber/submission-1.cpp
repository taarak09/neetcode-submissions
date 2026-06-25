class Solution {
public:
    int rob(vector<int>& nums) {
        //famous and most easy question of dp
        vector<int>dp1(nums.size(),-1);
        return dp(nums,nums.size()-1,dp1);

    }
    int dp(vector<int>& nums,int index,vector<int>& dp1)
    {
        if(index<0)
        {
            return 0;
        }
        int way1=0;
        int way2=0;
        if(index-2>=0){
          if(dp1[index-2]!=-1)
          {
            way1=dp1[index-2]+nums[index];
          }
          else{
            way1=dp(nums,index-2,dp1)+nums[index];
          }}else{
         way1=dp(nums,index-2,dp1)+nums[index];}
         
         if(index-1>=0){
            if(dp1[index-1]!=-1){
               way2=dp1[index-1];
            }
            else{
                way2=dp(nums,index-1,dp1);
            }}else{
         way2=dp(nums,index-1,dp1);}
        

         dp1[index]=max(way1,way2);
         return dp1[index];

       


    }
};
