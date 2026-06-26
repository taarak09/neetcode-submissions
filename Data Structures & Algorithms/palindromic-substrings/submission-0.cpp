class Solution {
public:
    int countSubstrings(string s) {
        //o(n*m)wala
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            //odd palindromic substrings 
            int left=i;
            int right=i;
            ans+=1;
            left--;
            right++;
            while(left>=0 && right<s.length())
            {
                if(s[left]==s[right])
                {
                    ans+=1;

                }
                else{
                    break;
                }
               left--;
               right++;
            }
            // even palindromic substring
            int le1=i;
            int r1=i+1;
            if(r1<s.length() && s[le1]==s[r1])
            {
                ans+=1;
            }
            else{
                continue;
            }
            le1--;
            r1++;
            while(le1>=0 && r1<s.length())
            {
                if(s[r1]==s[le1])
                {
                    ans+=1;
                }
                else{
                    break;
                }
                le1--;
                r1++;
            }

        }
  return ans;  }
};
