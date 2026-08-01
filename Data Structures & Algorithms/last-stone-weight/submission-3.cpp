class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      while(stones.size()!=1 ){
        sort(stones.begin(),stones.end());
        reverse(stones.begin(),stones.end());
       
       
        int a= stones[0];
        stones.erase(stones.begin()+0);
        int b=stones[0];
        stones.erase(stones.begin()+0);
        if(a==b)
        {

        }
        else if(a>b)
        {
          stones.push_back(a-b);
        }
        else{
          stones.push_back(b-a);
        }
        if(stones.empty())
        {
          return 0;
        }
      }
       if(stones.empty())
        {
          return 0;
        }
   return stones[0]; }
};
