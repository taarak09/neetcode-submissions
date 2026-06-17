class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        int i=0;
        int j;
        int k;
        while(i<nums.size()-2)
        {
            if(i>0  )
            {
                while( i<nums.size() && nums[i]==nums[i-1])
                {
                    i++;
                }
            }
            
             j=i+1;
              k=nums.size()-1;
              while(j<k)
              {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    while( j+1<nums.size() &&nums[j]==nums[j+1] )
                    {
                        j++;
                    }
                    j++;
                    while( k-1>=0 && nums[k]==nums[k-1])
                    {
                        k--;
                    }
                    k--;
                }
                else if (nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else{
                    j++;
                }
              }
              i++;
            
            
        }
   return result; }
};
