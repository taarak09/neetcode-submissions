class MinStack {
public:
stack<int>st;
vector<int>temp;
    MinStack() {
        
    }
    
    void push(int val) {
       temp.push_back(val);
       sort(temp.begin(),temp.end());
        st.push(val);
       
    }
    
    void pop() {
        int t1=st.top();
        st.pop();
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==t1)
            {
               temp.erase(temp.begin()+i);
            }
        }
        
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return temp[0];
    }
};
