class TimeMap {
public:
unordered_map<string,map<int,string>>mpp;


    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp]=value;
        
    }
    
    string get(string key, int timestamp) {
         string ans="";
        if(mpp.find(key)==mpp.end())
        {
            return "";
        }
        else{
           if(mpp[key].find(timestamp)!=mpp[key].end())
           {
            return mpp[key][timestamp];
           }
        else{
            for(auto const& [key ,value]:mpp[key])
            {
                if(key<=timestamp)
                {
                    ans=value;
                }
                else{
                    continue;
                }
            }
        }

           
        }
   return ans; }
};
