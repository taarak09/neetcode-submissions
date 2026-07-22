class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //proper binary search problem this is 
        //k is  a monotonically deceasing value 
        int low=1;
        int high=1e9;
        int ans=1e9;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(required_time(mid,piles)<=h)
            {
              
              high=mid-1;
              ans=min(ans,mid);

            }
            else{
               low=mid+1;
            }

        }

    return ans;}
    int required_time(int k,vector<int>& nums)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]/k==0)
            {
                ans+=1;
            }
            else{
                if(nums[i]%k==0){
          ans+=(nums[i]/k);}
          else{
            ans+=(nums[i]/k)+ 1;
          }
            }
        }
  return ans;  }
};
