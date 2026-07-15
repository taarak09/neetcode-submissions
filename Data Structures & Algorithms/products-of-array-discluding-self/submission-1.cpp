class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     // i will definitely win one day but on that day i will be completely broke fro my inside
     // nice algorithm mann yes,yes,yes
     int pro=1;
     int count=0;
     vector<int>result(nums.size(),0);
     for(int i=0;i<nums.size();i++)
     {
       if(nums[i]!=0)
       {
        pro*=nums[i];
       }
       else{
        count++;
       }
     }
     if(count==0)
     {
        for(int i=0;i<result.size();i++)
        {
          result[i]=pro/nums[i];
        }
     }
     else if (count==1)
     {
       for(int i=0;i<result.size();i++)
       {
        if(nums[i]!=0)
        {

        }
        else{
          result[i]=pro;
        }
       }
     }
     else{

     }

    return result;}
};
