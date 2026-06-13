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
                    asteroids[i]=INT_MIN;
                    break;

                }
                else if(abs(asteroids[i])>g){
                      st.pop();
                     
                   
                }
                else{
                     asteroids[i]=INT_MIN;
                    break;
                }}
                else{
                    st.push(asteroids[i]);
                    flag++;
                    break;
                }
                }
                if(asteroids[i]!=INT_MIN && flag==0)
                {
                    st.push(asteroids[i]);
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