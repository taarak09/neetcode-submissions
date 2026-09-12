class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //lets finish this easy question my friend come on 
        vector<int>dp(nums.size(),1);
        int ans=1;
        // this is the technique of the lis
        for(int i=1;i<nums.size();i++)
        {
           
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                  dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(dp[i],ans);
        }
    return ans;}
};