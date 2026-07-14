class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<pair<int,int>>arr;
      for(int i=0;i<nums.size();i++)
      {
        arr.push_back({nums[i],i});
      }
        
        vector<int>result;
        sort(arr.begin(),arr.end());
        int high=arr.size()-1;
        int low=0;
        while(low<high)
        {
          if(arr[low].first+arr[high].first==target)
          {
            result.push_back(arr[low].second);
            result.push_back(arr[high].second);
            break;
          }
          else if ( arr[low].first+arr[high].first>target)
          {
            high--;
          }
          else{
            low++;
          }
        }
        sort(result.begin(),result.end()); 
    
   return  result;}
};
