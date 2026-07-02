class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // comebck hard session 
        unordered_set<string>se;
        for(int i=0;i<wordDict.size();i++)
        {
            se.insert(wordDict[i]);
        }
        vector<int>dp1(s.length(),-1);
        if(dp(s.length()-1,se,s,dp1))
        {
            return true;
        }

  return false;  }
    int dp(int index,unordered_set<string>& se,string s,vector<int>& dp1)
    {
        if(index<0)
        {
            return 1;
        }
        // we need to try all possible combinations
        for(int i=index;i>=0;i--)
        {
            string currentword=s.substr(i,(index-i)+1);
            if(se.count(currentword))
            {
                if(i-1>=0){
                    if(dp1[index-1]==-1)
                    {
                       dp1[index-1]=dp(i-1,se,s,dp1);
                    }
                   if(dp1[index-1]==1)
                   {
                    return dp1[index-1];
                   }
                }
                else{
                    return 1;
                }
                
                  
            }
        }
  return 0;}
};
