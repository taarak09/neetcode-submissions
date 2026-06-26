class Solution {
public:
    int numDecodings(string s) {
        // decoding the number of ways 
        //tabulation is more practical;
        //in some questions we prefer tabulation by our own
        vector<int>dp(s.length(),-1);
        if(s[0]=='0')
        {
            return 0;
        }
        if(s[0]!=0)
        {
            dp[0]=1;
        }
       
        for(int i=1;i<s.length();i++)
        {
            int ways=0;
            int ways1=0;
            if(s[i]!='0')
            {
             ways=dp[i-1];
             //by considering only on e digit
             if(s[i-1]!='0')
             {
                 if(stoi(s.substr(i-1,2))<=26 && stoi(s.substr(i-1,2))>=10)
                 {
                    if(i-2>=0)
                    {
                        ways1=dp[i-2];
                    }
                    else{
                        ways1=1;
                    }
                   
                 }
                 else{
                    ways1=0;
                 }
             }
             else{
                ways1=0;
             }
            }
            else{
                ways=0;
               if(s[i-1]!='0')
               {
                   if(stoi(s.substr(i-1,2))<=26 && stoi(s.substr(i-1,2))>=10)
                   {

                      if(i-2>=0)
                      {
                        ways1=dp[i-2];
                      }
                      else{
                        ways1=1;
                      }
                   }
                   else{
                      ways1=0;
                   }
               }
               else{
                   ways1=0;
               }
            }
            dp[i]=ways+ways1;
        }
    return dp[s.length()-1];
    }
};
