class MinStack {
public:
// prper min stack implementation using the stndard logic not any kind of jugaad 
stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(st.empty())
        {
            st.push({val,val});
        }
        else{
            int temp=st.top().second;
            if(val<temp)
            {
                st.push({val,val});
            }
            else{
                st.push({val,temp});
            }
        }
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
         return st.top().second; 
    }
};
