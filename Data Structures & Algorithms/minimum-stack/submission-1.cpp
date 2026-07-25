class MinStack {
    //CREATE A STACK AND A MINSTACK, MINSTACK FOR FINDING THE MINIMUM
    stack<int> st;
    stack<int> Minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // push every ele in st
        st.push(val);
        //push only if the val is less than the top ele
        if(Minst.empty() || Minst.top()>=val){
            Minst.push(val);
        }
    }
    
    void pop() {
        if(st.top() == Minst.top()){
            
            Minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return Minst.top();
    }
};
