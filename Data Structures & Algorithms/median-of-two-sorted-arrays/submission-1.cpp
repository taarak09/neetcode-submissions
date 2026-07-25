class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        vector<int>temp;
        for(int i=0;i<nums1.size();i++)
        {
            temp.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            temp.push_back(nums2[i]);
        }
        sort(temp.begin(),temp.end());
       if(temp.size()%2!=0)
       {
           return temp[temp.size()/2];
       }
       else{
          int y=temp.size()/2;
          ans=(double)(temp[y]+temp[y-1])/2;
       }
    return ans;}
};
