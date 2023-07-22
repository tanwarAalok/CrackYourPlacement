```
class MyQueue {
public:
    stack<int> s1, s2;
    int front;
    MyQueue() {
        front = -1;
    }
    
    void push(int x) {
        if(s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int popped = s2.top();
        s2.pop();
        return popped;
    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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
```
