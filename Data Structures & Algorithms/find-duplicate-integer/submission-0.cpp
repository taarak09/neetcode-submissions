class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int h:nums)
        {
            if(mpp.find(h)!=mpp.end())
            {
                return h;
            }
            mpp[h]++;
        }
    }
};
