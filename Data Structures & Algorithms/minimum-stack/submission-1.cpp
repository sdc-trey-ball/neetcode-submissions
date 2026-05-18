class MinStack {
   stack<int> vals {};
   stack<int> mins {};
public:
    MinStack() {
    }
    
    void push(int val) {
        vals.push(val);
        mins.push(min(val, (mins.empty() ? val : mins.top())));
    }
    
    void pop() {
        vals.pop();
        mins.pop();
    }
    
    int top() {
       return vals.top();
    }
    
    int getMin() {
       return mins.top(); 
    }
};
