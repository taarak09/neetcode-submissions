class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
       vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]=i;
        }
       vector<int>arr;
       arr=nums;
       sort(arr.begin(),arr.end());// nlogn time
       int low=0;
       int high=arr.size()-1;
       while(low<high)
       {
          if(arr[low]+arr[high]==target)
          {
            if(arr[low]==arr[high])
            {
             
              result.push_back(occurance(nums,arr[low]));
               result.push_back(mpp[arr[low]]);
               sort(result.begin(),result.end());
              return result;

            }
            result.push_back(mpp[arr[low]]);
            result.push_back(mpp[arr[high]]);
             sort(result.begin(),result.end());
            return result; 
          }
          else if ( arr[low]+arr[high]>target)
          {
            high--;
          }
          else{
            low++;
          }
       }
     


    }
    int occurance(vector<int>&nums,int target)
    {
       for(int i=0;i<nums.size();i++)
       {
        if(target==nums[i])
        {
          return i;
        }
       }
    }
};
