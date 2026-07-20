class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //deque question it is 
        //front me hi deque ke hamesha max number rahegamini-boss ha bilkul bilkul bilkul
        deque<int>dq;
       int left=0;
       int right=0;
       vector<int>result;
       while(right<nums.size())
       {
            while( !dq.empty() && dq.back()<nums[right])
            {
                dq.pop_back();
            }
            dq.push_back(nums[right]);
         if((right-left)+1==k)
         {
            result.push_back(dq.front());
            if(dq.front()==nums[left])
            {
                dq.pop_front();
            }
            left++;
         }
        right++;
       }
   return result; }
};
