class MyQueue {
    stack<int>first; 
    stack<int>second; 
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        first.push(x); 
    }
    
    int pop() {
        if(second.empty()){
            while(!first.empty()){
              second.push(first.top()); 
            first.pop(); 
            }
        }
       int x = second.top(); 
        second.pop(); 
        return x; 
        
    }
    
    int peek() {
        if(second.empty()){
            while(!first.empty()){
              second.push(first.top()); 
         first.pop();
            }
         
        }
        return second.top();
    }
    
    bool empty() {
        return first.empty() && second.empty();
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