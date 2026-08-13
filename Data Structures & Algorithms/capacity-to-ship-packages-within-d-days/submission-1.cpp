class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=1;
        int right=1e9;
        int sum=0;
        int sum1=0;
        for(int i=0;i<weights.size();i++)
        {
            sum=max(weights[i],sum);
            sum1+=weights[i];
        }
        left=sum;
        right=sum1;
        int ans=1e9;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int days1=0;
           int temp=0;
            for(int i=0;i<weights.size();i++)
            {
                temp+=weights[i];
                if(temp<mid)
                {

                }
                else if(temp==mid)
                {
                    temp=0;
                    days1++;
                }
                else if(temp>mid)
                {
                    temp=weights[i];
                    days1++;

                }

            }
            if(days1==0)
            {
                days1=1;
            }
            if(temp!=0)
            {
                days1++;
            }

            if(days1>days)
            {
                left=mid+1;
            }
            else if(days1<=days)
            {
                 ans=min(ans,mid);
                right=mid-1;
            }

           
          
        }
  return ans;  }
};