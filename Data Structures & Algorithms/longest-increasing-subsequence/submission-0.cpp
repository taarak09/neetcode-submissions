class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      //memoization man
      vector<vector<int>>dp1(nums.size(),vector<int>(nums.size()+1,-1));
      return dp(nums,nums.size()-1,nums.size(),dp1);

    }
    int dp(vector<int>& nums,int index,int preindex,vector<vector<int>>& dp1)
    {
         int take=0;
        int non_take=0;
        if(index==0 && preindex==nums.size())
        {
            return 1;
        }
        if(index==0)
        {
            if(nums[preindex]>nums[index])
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        if(preindex==nums.size() &&index-1>=0)
        {
             if(dp1[index-1][index]!=-1){
                take=1+dp1[index-1][index];
            }else{
           take=1+dp(nums,index-1,index,dp1);}
        }
       else{
        if(index-1>=0){

            if(nums[index]<nums[preindex]){
            if(dp1[index-1][index]!=-1){
                take=1+dp1[index-1][index];
            }else{
                
        take=1+dp(nums,index-1,index,dp1);}}}}
        if(index-1>=0){
            if(dp1[index-1][preindex]!=-1){
               non_take=dp1[index-1][index]; }
               else{
         non_take=0+dp(nums,index-1,preindex,dp1);}}
         dp1[index][preindex]=max(take,non_take);
         return dp1[index][preindex];
    }
};
