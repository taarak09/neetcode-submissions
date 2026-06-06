class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>arr;
        int pro=1;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]!=0){
        pro*=nums[i];}
        if(nums[i]==0)
        {
            arr.push_back(i);
            
        }
       }
       if(arr.size()>1)
       {
        vector<int>r(nums.size(),0);
        return r;

       }
       vector<int>result;
       if(arr.size()==1){
       for(int i=0;i<nums.size();i++)
       {
         if(nums[i]!=0)
         {
            result.push_back(0);
         }
         else{
           result.push_back(pro);
         }
       }
       }
       if(arr.empty())
       {
         for(int i=0;i<nums.size();i++)
         {
            result.push_back(pro/nums[i]);
         }
       }


   return result; }
};
