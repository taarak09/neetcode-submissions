class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // it is probably like a take / no -take prroblem 
        unordered_map<string,int>mpp;
        for(int i=0;i<dictionary.size();i++)
        {
            mpp[dictionary[i]]++;
        }
        //you can use the strings multiple timmes my friend 
        vector<int>dp(s.length(),0);
        string h="";
        h+=s[0];
        if(mpp.find(h)!=mpp.end())
        {
            dp[0]=0;
        }
        else{
            dp[0]=1;
        }
        for(int i=1;i<dp.size();i++)
        {
            h+=s[i];
            int skip=1+dp[i-1];
            int non_skip=INT_MAX;
            string k="";
            for(int j=i;j>=0;j--)
            {
                k=s[j]+k;
                if(mpp.find(k)!=mpp.end())
                {
                    if(j==0)
                    {
                        non_skip=0;
                    }else{
                    non_skip=min(non_skip,dp[j-1]);}
                }
                
            }
            dp[i]=min(skip,non_skip);

        }
    return dp[s.length()-1];}
};