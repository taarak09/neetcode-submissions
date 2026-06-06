class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //longest consecutive sequence
        sort(nums.begin(),nums.end());
        if(nums.empty())
        {
            return 0;
        }
        int left=0;
        int right=1;
        int count=1;
        int ans=INT_MIN;
        while(left <nums.size() && right<nums.size())
        {

           if (nums[right]==nums[left]+1 || nums[right]==nums[left])
           {
            if( nums[right]==nums[left])
            {
                right++;
                left++;

            }else{
               right++;
               left++;
               count++;
                ans=max(ans,count);}
           }
            else{
                ans=max(ans,count);
              count=1;
              left=right;
              right++;

            }
            
        }
        if(ans==INT_MIN)
        {
            return 1;
        }
   return ans; }
};
