class MinStack {
public:
stack<pair<int,vector<int>>>st;
vector<int>temp;
    MinStack() {
        
    }
    
    void push(int val) {
       temp.push_back(val);
       sort(temp.begin(),temp.end());
        st.push({val,temp});
       
    }
    
    void pop() {
       int u=st.top().first;
        st.pop();
       for(int i=0;i<temp.size();i++)
       {
        if(temp[i]==u)
        {
            temp.erase(temp.begin()+i);
            break;
        }
       }
        
        
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
     return  st.top().second[0];
    }
};
