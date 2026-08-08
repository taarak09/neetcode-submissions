class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //lets rotatae the array my friendd
        vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums.clear();
        nums=temp;
    }
};