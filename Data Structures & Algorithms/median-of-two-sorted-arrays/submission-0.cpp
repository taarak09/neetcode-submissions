class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        for(int i:nums1)
        {
            temp.push_back(i);
        }
        for(int o: nums2)
        {
            temp.push_back(o);
        }
        if(temp.empty())
        {
            return 0;
        }
     double ans=0;
        sort(temp.begin(),temp.end());
       int u=temp.size();
        if(u%2!=0)
        {
            return (double)temp[(u/2)];
        }
        else{
            int g=u/2;
            double a= (double)temp[g];
            double b=(double)temp[g-1];
             ans=(a+b)/2;
        }
    return ans;}
};
