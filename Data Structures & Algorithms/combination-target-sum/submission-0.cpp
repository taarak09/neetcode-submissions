class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        answer(nums,target,result,temp,0,0);
        return result;

    }
    void answer(vector<int>& nums,int target,vector<vector<int>>& result,vector<int>& temp,int index,int sum)
    {
        if(index>=nums.size() ||target<=0)
        {
              if(target==0)
              {
                result.push_back(temp);
              }
           
            return;
        }
       
    
       temp.push_back(nums[index]);
       answer(nums,target-nums[index],result,temp,index,sum);
       temp.pop_back();
       answer(nums,target,result,temp,index+1,sum);


    }
    };

