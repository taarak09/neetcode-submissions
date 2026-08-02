class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>>pq;
        
        for(int i=0;i<points.size();i++)
        {
            pq.push({dist(points[i][0],points[i][1]),{points[i][0],points[i][1]}});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<vector<int>>result;
        while(!pq.empty())
        {
            double temp=pq.top().first;
            vector<int> y=pq.top().second;
            pq.pop();
            result.push_back(y);
        }

   return result; }
    double dist(int i,int j)
    {
        double r=((i*i) + (j*j));
       return  sqrt(r);
    }
};
