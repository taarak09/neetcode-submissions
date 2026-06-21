class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>result;
        vector<int>temp;
        answer(nums,0,result,temp);
    return result;
    }
     void answer(vector<int>&  nums,int index,vector<vector<int>>& result,vector<int>& temp)
    {
      
       if(index>=nums.size())
       {
        result.push_back(nums);
        return ;
       }
     for(int i=index;i<nums.size();i++)
     {
        swap(nums[i],nums[index]);
        answer(nums,index+1,result,temp);
        swap(nums[i],nums[index]);

     }

    }
};
