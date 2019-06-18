class MyStack {
private:
    queue<int> q1, q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int cnt = 0;
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
            cnt += 1;
        }
        cnt -= 1;
        while(cnt--) {
            q1.push(q2.front());
            q2.pop();
        }
        int re = q2.front();
        q2.pop();
        return re;
    }
    
    /** Get the top element. */
    int top() {
        int pre;
        while (!q1.empty()) {
            q2.push(q1.front());
            pre = q1.front();
            q1.pop();
        }
        while (!q2.empty()) {
            q1.push(q2.front());
       
            q2.pop();
        }
        return pre;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */