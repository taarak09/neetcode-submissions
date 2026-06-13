class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //monotonic stack 
        stack<pair<int,int>>st;
        int count=0;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            count=0;
            for(int j=i;j<nums2.size();j++)
            {
                if(nums2[j]>nums2[i])
                {
                    count++;
                    st.push({nums2[i],nums2[j]});
                    break;
                }
            }
            if(count==0)
            {
                st.push({nums2[i],-1});
            }
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<nums1.size();i++)
        {
            mpp[nums1[i]]=-1;
        }
        while(!st.empty())
        {
            int a=st.top().first;
            int b=st.top().second;
            if(mpp.find(a)!=mpp.end())
            {
                mpp[a]=b;
            }
            st.pop();
        }
        vector<int>result;
       for(int i=0;i<nums1.size();i++)
       {
         result.push_back(mpp[nums1[i]]);
       }
    return result;}
};