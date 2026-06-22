class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string temp="";
        answer(result,temp,n,0,0);
        return result;
    }
    void answer(vector<string>& result,string & temp,int n,int open ,int close)
    {
        if(temp.size()>=2*n)
        {
            result.push_back(temp);
            return ;
        }
        if(open<n)
        {
            temp.push_back('(');
            answer(result,temp,n,open+1,close);
            temp.pop_back();
        }
        if(close<open)
        {
            //thats why we generate only valid paira close are always less than our open breackets and always after the open brkets
            temp.push_back(')');
            answer(result,temp,n,open,close+1);
            temp.pop_back();
        }
    }
};
