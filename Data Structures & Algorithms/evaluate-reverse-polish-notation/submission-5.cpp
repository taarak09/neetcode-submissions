class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i=0;i<tokens.size();i++)
        {
          if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
          {
            if(tokens[i]=="+")
            {
              int a=  stoi(st.top());
              st.pop();
              int  b=stoi(st.top());
              st.pop();
              int ans=a+b;
              st.push(to_string(ans));
              

            }
            else if (tokens[i]=="-")
            {
              int a=  stoi(st.top());
              st.pop();
              int  b=stoi(st.top());
              st.pop();
              int ans=b-a;
              st.push(to_string(ans));
            }
            else if (tokens[i]=="*")
            {

              int a=  stoi(st.top());
              st.pop();
              int  b=stoi(st.top());
              st.pop();
              int ans=a*b;
              st.push(to_string(ans));
            }
            else{
               int a=  stoi(st.top());
              st.pop();
              int  b=stoi(st.top());
              st.pop();
              int ans=b/a;
              st.push(to_string(ans));



            }

          }
          else{
            st.push(tokens[i]);
          }

        }
        int ans=stoi(st.top());
    return ans;}
};
