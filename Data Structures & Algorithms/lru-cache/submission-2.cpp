//optimal solution
class LRUCache {
public:
list<int>ke;
unordered_map<int,int>mpp;
int size1=0;
    LRUCache(int capacity) {
        size1=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            auto it=find(ke.begin(),ke.end(),key);
            ke.erase(it);
            ke.push_front(key);

              return mpp[key];
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            auto it=find(ke.begin(),ke.end(),key);
            ke.erase(it);
            ke.push_front(key);
            mpp[key]=value;
        }
        else{
            if(ke.size()<size1)
            {
                mpp[key]=value;
                ke.push_front(key);
            }
            else
            {
                mpp.erase(ke.back());
                ke.pop_back();
                mpp[key]=value;
                ke.push_front(key);

            }
        }
    }
};
