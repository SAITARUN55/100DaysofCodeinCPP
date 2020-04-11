class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
     s.push_back(x);
        if (min.empty() || x <= min.back())
            min.push_back(x);   
    }
    
    void pop() {
        if (top() == min.back())
            min.pop_back();
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
         return min.back();
    }
    private:
    vector<int> s, min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
