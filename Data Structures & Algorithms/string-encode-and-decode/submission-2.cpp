class Solution {
public:

    string encode(vector<string>& strs) {
       string result="";
       for(int i=0;i<strs.size();i++)
       {
         result+=strs[i];
         result+='\0';
       }
       return result;
       
    }

    vector<string> decode(string s) {
        vector<string>result;
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='\0')
            {
               temp+=s[i];
            }
            else{
                result.push_back(temp);
                temp="";

            }
        }
        if(temp!="")
        {
            result.push_back(temp);
        }
        return result;
    }
};
