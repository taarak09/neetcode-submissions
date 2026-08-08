class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(i+nums[i]);
        }
        int far=0;
        int end=0;
        int jumps=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            far=max(far,temp[i]);
            if(i==end)
            {
               jumps++;
               end=far;
            }

              

        }
    return jumps;}
};
