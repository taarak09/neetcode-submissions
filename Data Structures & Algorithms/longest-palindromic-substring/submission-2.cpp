class Solution {
public:
    string longestPalindrome(string s) {
        // i think this much of the hint is enough for me to solve this question
        // mere pass iska solution hai
        int ans=0;
        string h;
        for(int i=0;i<s.length();i++)
        {
           int left=i;
           int right=i;
           if((right-left)+1>ans)
                {
                    ans=(right-left)+1;
                    h=s.substr(left,ans);

                }
           left--;
           right++;
        
           while(left>=0 && right<s.length()){
           if(left>=0 && right<s.length())
           {
               if(s[left]==s[right])
               {
                      if((right-left)+1>ans)
                {
                    ans=(right-left)+1;
                    h=s.substr(left,ans);

                }
               }
               else{
               
               
                break;

               }
           }
          

           left--;
           right++;
           }
             // for even length of palindromic strings  
             //even palindromic condition 
             int le1=i;
             int r1=i+1;
             if(r1<s.length() && s[r1]==s[le1] )
             {
                if( (r1-le1)+1>ans){
                ans=(r1-le1)+1;
                h=s.substr(le1,ans);}
             }
             else{
                continue;
             }
             le1--;
             r1++;
             while(le1>=0 && r1<s.length())
             {
                if(s[le1]==s[r1])
                {
                    if((r1-le1)+1>ans)
                    {
                      ans=(r1-le1)+1;
                      h=s.substr(le1,ans);
                    }
                }
                else{
                    break;
                }
                le1--;
                r1++;
             }
             
         
        }
    
          
   return h; }
};
