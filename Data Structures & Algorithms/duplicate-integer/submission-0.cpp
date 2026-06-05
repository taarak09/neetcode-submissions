class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int u:nums)
        {
            mpp[u]++;
            if(mpp[u]>1)
            {
                return true;
            }
        }
        
    return false;}
};