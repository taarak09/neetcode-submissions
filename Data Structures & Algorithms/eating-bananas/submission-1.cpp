class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       
        long long low=0;
        long high=1e9;
        long long ans=INT_MAX;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            long long hour=0;
            for(int r:piles)
            {
                if(mid!=0){
                hour+=(r/mid);
                if(r%mid!=0)
                {
                    hour++;
                }}
            }
            if(mid==0)
            {
                low++;
                continue;
            }
            if(hour<=h)
            {
                ans=min(ans,mid);
               high=mid-1;
            }
            else {
                low=mid+1;
            }

        }
   return ans; }
};