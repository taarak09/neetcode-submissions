class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        answer(nums,0,result,temp);
    return result;}
   void answer(vector<int>&  nums,int index,vector<vector<int>>& result,vector<int>& temp)
    {
       // all possible subsequences  using recursion
       if(index>=nums.size())
       {
        result.push_back(temp);
        return ;

       }
       temp.push_back(nums[index]);
       answer(nums,index+1,result,temp);
       temp.pop_back();
       answer(nums,index+1,result,temp);








    }
};
