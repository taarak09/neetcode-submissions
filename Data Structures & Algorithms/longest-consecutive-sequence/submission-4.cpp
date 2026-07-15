class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //by doing sliding window
        int right=0;
        int left=0;
        deque<int>dq;
        int ans=0;
        while(right<nums.size())
        {
          dq.push_back(nums[right]);
          if(dq.size()>1)
          {
            if(dq.back()==dq[dq.size()-2]+1)
            {
             ans=max(ans,(int)dq.size());
            }
            else if (dq.back()==dq[dq.size()-2])
            {
               dq.pop_back();
            }
            else{
                 ans=max(ans,(int)dq.size()-1);
                dq.clear();
                dq.push_back(nums[right]);
                left++;
            }
          }
           ans=max(ans,(int)dq.size());
           right++;
        }
   return ans; }
};
