class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(is_sorted(nums.begin(),nums.end()))
        {
            auto it = lower_bound(nums.begin(),nums.end(),target);
            if(it!=nums.end() && *it==target)
            {
                return ( it-nums.begin());
            }
            else{
                return -1;
            }
        }
        else{
            vector<int>t1;
            vector<int>t2;
             int index=0;
            for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i]<=nums[i+1])
                {

                }
                else{
                  index=i+1;
                  break;
                }
            }
            int var=0;
            while(var<index)
            {
                t1.push_back(nums[var]);
                var++;
            }
           
            while(var<nums.size())
            {
                t2.push_back(nums[var]);
                var++;
            }
            auto it1=lower_bound(t1.begin(),t1.end(),target);
            auto it2=lower_bound(t2.begin(),t2.end(),target);
            if(it1!=t1.end() && *it1==target  )
            {
                return ( it1-t1.begin());
            }
            if(it2!=t2.end() && *it2==target)
            {

               return (((it2-t2.begin())+t1.size()));
            }

        }
   return -1; }
};
