class Solution {
public:
    bool canJump(vector<int>& nums) {
        // jump game is a good question man 
        //i only need to skip zeros here 
        // good greedy approach man yes yes yes 
        int maxindex=0;
        for(int i=0;i< nums.size();i++)
        {
            if(i>maxindex)
            {
                return false;
            }
            maxindex=max(maxindex,i+nums[i]);
        }
   return true; }
};
