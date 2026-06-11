class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int ans=0;
        if(tokens.size()==1)
        {
            return stoi(tokens[0]);
        }
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                if(tokens[i]=="+")
                {
                   string a= st.top();
                   st.pop();
                   string b= st.top();
                   st.pop();
                   int t1;
                   int t2;
                  t1= string_to_integer_converter(a);
                  t2=string_to_integer_converter(b);
                  ans=(t1+t2);
                  st.push(integer_to_string_convereter(ans));
                   
                }
                else if ( tokens[i]=="-")
                {
                 string a= st.top();
                   st.pop();
                   string b= st.top();
                   st.pop();
                   int t1;
                   int t2;
                  t1= string_to_integer_converter(a);
                  t2=string_to_integer_converter(b);
                  ans=(t2-t1);
                   st.push(integer_to_string_convereter(ans));
                }
                else if (tokens[i]=="*")
                {
                     string a= st.top();
                   st.pop();
                   string b= st.top();
                   st.pop();
                   int t1;
                   int t2;
                  t1= string_to_integer_converter(a);
                  t2=string_to_integer_converter(b);
                  ans=(t2*t1);
                  st.push(integer_to_string_convereter(ans));
                }
                else{
                     string a= st.top();
                   st.pop();
                   string b= st.top();
                   st.pop();
                   int t1;
                   int t2;
                  t1= string_to_integer_converter(a);
                  t2=string_to_integer_converter(b);
                  ans=(t2/t1);
                  st.push(integer_to_string_convereter(ans));
                }

            }
            else{
                st.push(tokens[i]);
            }
        }
  return ans;  }
    int string_to_integer_converter(string a)
    {
        return stoi(a);
    }
    string integer_to_string_convereter(int ans)
    {
         return to_string(ans);
    }
};
