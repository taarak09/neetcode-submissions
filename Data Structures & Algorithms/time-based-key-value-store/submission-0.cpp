class TimeMap {
public:
unordered_map<string,vector<pair<int ,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
         string ans="";
        if(mpp.find(key)==mpp.end())
        {
            return "";
        }
        else{
           
            sort(mpp[key].begin(),mpp[key].end());
            for(pair<int,string>    h:mpp[key])
            {
                if(h.first<=timestamp)
                {
                    ans=h.second;
                }
            }
        }
   return ans; }
};
