class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int temp=0;
        if(k==1)
        {
            return nums;
        }
        int comp=0;
        vector<int>result;
        if(nums.size()>=k){
        for(int i=0;i<k;i++)
        {
            dq.push_back(nums[i]);
           
        }
        comp=maximum(dq);
        result.push_back(comp);
        }
        else{
            deque<int>f(nums.begin(),nums.end());
            result.push_back(maximum(f));
            return result;
        }
        for(int i=k;i<nums.size();i++)
        {
            dq.push_back(nums[i]);
            temp=dq[0];
            if(dq.size()>k)
            {
                dq.pop_front();
            }
            if(comp!=temp){
            if(dq[dq.size()-1]>comp)
            {
                result.push_back(dq[dq.size()-1]);
            }
            else{
            result.push_back(comp);}}
            else{
               
                comp=maximum(dq);
                 result.push_back(comp);
            }
            comp=result[result.size()-1];
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
