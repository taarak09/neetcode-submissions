class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
        sort(mpp[key].begin(),mpp[key].end());
    }
    
    string get(string key, int timestamp) {
        string ans="";
      for(int i=0;i<mpp[key].size();i++)
      {
        if(mpp[key][i].first<=timestamp)
        {
            ans=mpp[key][i].second;
        }

      }
        
   return ans; }
};
