class LRUCache {
public:
unordered_map<int,pair<int,int>>mpp;
int size1=0;
int count=0;
    LRUCache(int capacity) {
        
        size1=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())
        {
            return -1;
        }else{
            count++;
            mpp[key].second=count;
            return mpp[key].first;
        }

    }
    
    void put(int key, int value) {
        count++;
        if(mpp.find(key)!=mpp.end())
        {
            mpp[key].first=value;
            mpp[key].second=count;
        }
        else{
            if(mpp.size()<size1)
            {
              mpp[key].first=value;
              mpp[key].second=count;
            }
            else{
              priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
              for(auto const&[key,value]:mpp)
              {
                pq.push({mpp[key].second,key});
              }
             
              mpp.erase(pq.top().second);
              mpp[key].first=value;
              mpp[key].second=count;
            }
        }
    }
};
