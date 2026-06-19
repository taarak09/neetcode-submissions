class Solution {
public:
    int reverse(int x) {
   int flag=0;
        if(x<0)
        {
            flag=1;
            x/=-1;
        }
        vector<int>temp;
        
        while(x!=0)
        {
           temp.push_back(x%10);
           x=x/10;
        }
     int low=0;
     int high=temp.size()-1;
     while(low<high)
     {
        swap(temp[low],temp[high]);
        low++;
        high--;
     }
       long long ans=0;
        for(int i=0;i<temp.size();i++)
        {
            double p = pow(10,i);
            ans+=p*temp[i];
        }
        if(ans>INT_MAX)
        {
            return 0;
        }
        if(flag==1)
        {
            ans*=-1;
        }
        
    return ans;}
};
