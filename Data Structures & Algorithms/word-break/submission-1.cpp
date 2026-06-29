class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // we need to look after only the word dictionary
        // a god question 
        unordered_set<string>k(wordDict.begin(),wordDict.end());
        vector<int>dp(s.length(),-1);
        if(ans(s,s.length()-1,k,dp))
        {
            return true;
        }
        else{
            return false;
        }
        
    }
    int ans(string s,int index,unordered_set<string>&k,vector<int>& dp)
    {
        if(index<0)
        {
           return 1;
        }
       
        for(int i=index;i>=0;i--)
        {
            string currentword=s.substr(i,(index-i)+1);
            if(k.count(currentword))
            {
                if(i-1>=0){
                    if(dp[i-1]==-1)
                    {
                       dp[i-1]= ans(s,i-1,k,dp);
                          
                       
                    }
                    else{
                      
                    }
                  

                }
                else{
                    return 1;
                }
              if(dp[i-1]==1)
            {
                return 1;
            }
            }
           
        }
     
  return 0;  }
};
