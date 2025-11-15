class MyQueue {

private:
stack<int> s1, s2;


public:
    MyQueue() {   
    }
    
    void push(int x) {

        
        while(!s1.empty())
        {
            int y = s1.top();
            s2.push(y);
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty())
        {
            int z = s2.top();
            s1.push(z);
            s2.pop();
        }

    }
    
    int pop() {
        int z = s1.top();
        s1.pop();
        return z;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        //cout << "s1 size:" << s1.size() << " s1 top: " << s1.top() << endl;
        return s1.empty();
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

///////// Using single stack

class MyQueue {
    stack<int> s;

public:
    MyQueue() {
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int x = s.top();
        s.pop();

        if(s.empty())
            return x;
        
        int y = pop();
        s.push(x);
        return y;
    }
    
    int peek() {
        int x = s.top();
        s.pop();

        if(s.empty())
        {
            s.push(x);
            return x;
        }
        
        int y = peek();
        s.push(x);
        return y;
    }
    
    bool empty() {
        return s.empty();
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
