class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      simulation(stones);
      if(stones.size()==1)
      {
        return stones[0];
      }

   return 0; }
    void simulation(vector<int>& stones)
    {
        if(stones.size()<2){
            return ;
        }
        sort(stones.begin(),stones.end());
          priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int r : stones)
        {
            pq.push(r);
            if(pq.size()>2)
            {
                pq.pop();
            }
        }
       int r= pq.top();
       pq.pop();
       int u=pq.top();
       pq.pop();
       if(r==u)
       {
         stones.pop_back();
         stones.pop_back();
       }
       else 
       {
         int temp=max(r,u);
         int t1=min(r,u);
         stones.pop_back();
         stones.pop_back();
         stones.push_back(temp-t1);

       }
       if(stones.size()>=2)
       {
        simulation(stones);
       }
    }
};
