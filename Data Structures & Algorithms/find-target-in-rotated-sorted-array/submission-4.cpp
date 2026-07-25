class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target)
            {
                return 0;
            }
            else{
                return -1;
            }
        }
        vector<int>t1;
        vector<int>t2;
        int bp=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {

            }
            else{
               bp=i+1;
               break;
            }
        }
        if(bp==-1)
        {
          return   binary_search(nums,target);
        }
        for(int i=0;i<bp;i++)
        {
            t1.push_back(nums[i]);
        }
        for(int i=bp;i<nums.size();i++)
        {
            t2.push_back(nums[i]);
        }
        int r=binary_search(t1,target);
        int f=binary_search(t2,target);
        if(r!=-1)
        {
            return r;
        }
        else if (f!=-1){
            return f+t1.size();

        }
       


    return -1;}
    int binary_search(vector<int>& nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
          int mid= (low+high)/2;
          if(nums[mid]==target)
          {
            return mid;
          }
          else if (nums[mid]<target)
          {
            low=mid+1;
          }
          else{
            high=mid-1;
          }


        }
    return -1;}
};
