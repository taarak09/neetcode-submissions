class Solution {
public:
    bool isHappy(int n) {
        vector<int>temp;
        unordered_map<int,int>mpp;
        mpp[n]++;
        while(n!=1){
        while(n!=0)
        {
            temp.push_back((n%10));
            n/=10;
        }
        int new1=0;
        for(int i=0;i<temp.size();i++)
        {
            new1+=(temp[i]*temp[i]);
        }
        n=new1;
        if(mpp.find(n)!=mpp.end())
        {
            return false;
        }

        mpp[n]++;
        temp.clear();
        }
   return true; }
};
