class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>result;
        int low=0;
        int high=numbers.size()-1;
        while(low<high)
        {
              if(target==(numbers[low]+numbers[high]))
              {
                result.push_back(low+1);
                result.push_back(high+1);
                break;
              }

              else if(target>(numbers[low]+numbers[high]))
              {
                low++;
              }
              else{
                high--;
              }
        }
   return result; }
};
