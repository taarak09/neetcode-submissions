class Solution {
public:

    string encode(vector<string>& strs) {
        string temp="";
         for(int i=0;i<strs.size();i++)
         {
            temp+=strs[i];
            temp+='\0';

         }
         return temp;
    }

    vector<string> decode(string s) {
        string temp="";
        vector<string>result;
       for(int i=0;i<s.length();i++)
       {
          if(s[i]!='\0')
          {
            temp+=s[i];
          }
          else{
           result.push_back(temp);
           temp.clear();
          }
       }
   return result; }
};
