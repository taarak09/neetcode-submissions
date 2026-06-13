class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int flag=0;
        
       
        for(int i=0;i<asteroids.size();i++)
        {
           
              if(!st.empty() && st.top()>0 && asteroids[i]<0)
              {
                while(!st.empty()){
               
              if(!st.empty() && st.top()>0 && asteroids[i]<0){
                int g=st.top();
                if(abs(asteroids[i])==g)
                {
                    st.pop();
                    break;

                }
                else if(abs(asteroids[i])>g){
                      st.pop();
                      flag++;
                   
                }
                else{
                    break;
                }}
                else{
                    st.push(asteroids[i]);
                    break;
                }
                }
               if(flag==i)
               {
                st.push(asteroids[i]);
                flag=0;
               }

              }
              else{
                   st.push(asteroids[i]);
              }
               
            
            
        }
     
        vector<int>result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
    return result;}
};