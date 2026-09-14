class MinStack {
    stack<int> actualstack;
    stack<int> minstack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        actualstack.push(val);
        if(actualstack.size()==1) minstack.push(actualstack.top());
        else if(val <= minstack.top()) minstack.push(val);
        
    }
    
    void pop() {
        if(actualstack.top()==minstack.top()) minstack.pop();

        actualstack.pop();

        
    }
    
    int top() {

        return actualstack.top();
        
    }
    
    int getMin() {

        return minstack.top();
        
    }
};
