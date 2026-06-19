class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]!=0)
        {
            return 0;
        }
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]==(nums[i]+1))
            {

            }
            else{
                ans=nums[i]+1;
                break;
            }
        }
        if(ans==-1)
        {
            return n;
        }
  return ans;  }
};
