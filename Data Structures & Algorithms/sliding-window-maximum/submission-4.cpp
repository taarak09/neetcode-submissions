class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int left=0;
        int right=0;
        vector<int>result;
        while(right<nums.size())
        {
            while(!dq.empty() && nums[dq.back()]<nums[right])
            {
                dq.pop_back();
            }
             dq.push_back(right);
             while(!dq.empty() && dq.front()<(right-k+1))
             {

                dq.pop_front();

             }
             if(right>=k-1)
             {
                result.push_back(nums[dq.front()]);
             }
            right++;
        }
   return result; }
};
