class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1=0;
        int sum2=0;
       for(int i=0;i<gas.size();i++)
       {
          sum1+=gas[i];
          sum2+=cost[i];
       }
       if(sum1<sum2)
       {
        return -1;
       }
        for(int i=0;i<gas.size();i++)
        {
           if(check(gas,cost,i))
           {
            return i;
           }
        }
   return -1; }
    bool check(vector<int>&gas,vector<int>& cost,int index)
    {
         if(gas[index]==0 && cost[index]==0)
            {
                return false;
            }
        int capacity=0;
        for(int i=index;i<gas.size();i++)
        {
           
          capacity+=gas[i]-cost[i];
          if(capacity<0)
          {
            return false;
          }
        }
        for(int i=0;i<index;i++)
        {
            capacity+=gas[i]-cost[i];
            if(capacity<0)
          {
            return false;
          }
        }

    return true;}
};