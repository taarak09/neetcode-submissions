class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;
        if(nums.size()>=k){
        for(int i=0;i<k;i++)
        {
            dq.push_back(nums[i]);
        }
        result.push_back(maximum(dq));
        }
        else{
            deque<int>f(nums.begin(),nums.end());
            result.push_back(maximum(f));
            return result;
        }
        for(int i=k;i<nums.size();i++)
        {
            dq.push_back(nums[i]);
            if(dq.size()>k)
            {
                dq.pop_front();
            }
            result.push_back(maximum(dq));
        }
 return result;   }
    int maximum(deque<int>dq)
    {
        for(int i=0;i<dq.size()-1;i++)
        {
           if(dq[i]>dq[i+1])
           {
            swap(dq[i],dq[i+1]);
           }
        }
  return dq[dq.size()-1];  }
};
