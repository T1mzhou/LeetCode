class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> keepstack;
    stack<int> min;
    
    MinStack() {
        
    }
    
    void push(int x) {
        keepstack.push(x);
        if (min.empty() || x <= min.top()) min.push(x);
    }
    
    void pop() {
        if (keepstack.top() == min.top()) min.pop();
        keepstack.pop();
    }
    
    int top() {
        return keepstack.top();
    }
    
    int getMin() {
        return min.top();
    }
};