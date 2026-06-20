class Solution {
public:
    int findMin(vector<int> &nums) {
        if(is_sorted(nums.begin(),nums.end()))
        {
            return nums[0];
        }
        else{
            int ans=0;
            for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i]<=nums[i+1])
                {

                }
                else{
                    return nums[i+1];
                }
            }
        }
    return -1;}
};
