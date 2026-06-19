class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto const&[key,value]:mpp)
        {
            if(value==1)
            {
              ans= key;
              break;
            }
        }
        return ans;
    }
};
