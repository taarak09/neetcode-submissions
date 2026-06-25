class Solution {
public:
    int rob(vector<int>& nums) {
        // we always follow a memoization technique to win in such questions
        //good logic 
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>temp;
        vector<int>t1;
        for(int i=0;i<nums.size()-1;i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++)
        {
            t1.push_back(nums[i]);
        }

        vector<int>dp1(temp.size(),0);
        vector<int>dp2(t1.size(),0);
       
         dp(temp,dp1,temp.size()-1);
         dp(t1,dp2,t1.size()-1);
        
         return max(dp1[dp1.size()-1],dp2[dp2.size()-1]);
    }
    int dp(vector<int>& nums,vector<int>& dp1,int index)
    {
        if(index<0)
        {
            return 0;
        }
       
        int way1=0;
        int way2=0;
         if(index-2>=0){
            if(dp1[index-2]!=0)
            {
                way1=dp1[index-2]+nums[index];
            }
            else
            {
                way1=dp(nums,dp1,index-2)+nums[index];
            }
         
         }else{
         way1=dp(nums,dp1,index-2)+nums[index];}
         
         
         if(index-1>=0){
            if(dp1[index-1]!=0)
            {
                way2=dp1[index-1];

            }else{
              way2=dp(nums,dp1,index-1);
            }
         }else{
         way2=dp(nums,dp1,index-1);}

         dp1[index]=max(way1,way2);
         return dp1[index];

    }
};
