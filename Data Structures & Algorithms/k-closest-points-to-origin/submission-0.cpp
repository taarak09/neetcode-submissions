
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //priority queue concept
        // i love this concept man , i faell in love with this concept of maintaining braket of size k 
        priority_queue<pair<double,vector<int>>>pq;
      
      
        
        for(int i=0;i<points.size();i++)
        {
            pq.push( {distance(points[i][0],points[i][1]),{points[i][0],points[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<vector<int>>result;
        for(int i=0;i<k;i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
           
        }


   return result; }
    double distance ( int i,int j)
    {
       return sqrt(i*i +j*j);
    }
};
