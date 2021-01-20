class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    stack<int> stk;
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        //最后进来的元素压栈压到最底部
        while(!stk.empty()){
            temp.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!temp.empty()){
            stk.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int a=stk.top();
        stk.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */